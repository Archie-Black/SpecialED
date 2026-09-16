/** SpecialED — learning persistence. Public isolate. Not the private OS. */

const KEY = "specialed.osv01d.v1";

export type Memory = {
  plays: number;
  lastT: number;
  muted: boolean;
  lookFails: number;
  lookOk: boolean;
  strength: number;
  updated: number;
};

const DEFAULT: Memory = {
  plays: 0,
  lastT: 0,
  muted: false,
  lookFails: 0,
  lookOk: true,
  strength: 1,
  updated: 0,
};

export function loadMemory(): Memory {
  try {
    const raw = localStorage.getItem(KEY);
    if (!raw) return { ...DEFAULT };
    const parsed = JSON.parse(raw) as Partial<Memory>;
    return { ...DEFAULT, ...parsed };
  } catch {
    return { ...DEFAULT };
  }
}

export function saveMemory(patch: Partial<Memory>): Memory {
  const next = { ...loadMemory(), ...patch, updated: Date.now() };
  try {
    localStorage.setItem(KEY, JSON.stringify(next));
  } catch {
    /* private mode */
  }
  return next;
}

/** Adapt look: two WebGL failures and we drop the compositor. */
export function noteLookFail(): Memory {
  const m = loadMemory();
  const fails = m.lookFails + 1;
  return saveMemory({
    lookFails: fails,
    lookOk: fails < 2,
    strength: Math.max(0.35, m.strength * 0.82),
  });
}

export function noteLookOk(): Memory {
  const m = loadMemory();
  return saveMemory({
    lookOk: true,
    strength: Math.min(1, m.strength + 0.04),
  });
}

export function notePlay(t: number, muted: boolean): Memory {
  return saveMemory({ lastT: t, muted, plays: loadMemory().plays + 1 });
}

export function shouldUseLook(): boolean {
  return loadMemory().lookOk;
}
