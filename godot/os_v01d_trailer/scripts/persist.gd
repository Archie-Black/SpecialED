extends Node
## SpecialED learning persistence. user://specialed.json

const PATH := "user://specialed.json"

var plays: int = 0
var last_t: float = 0.0
var muted: bool = false
var look_fails: int = 0
var look_ok: bool = true
var strength: float = 1.0

func _ready() -> void:
	_load()

func _load() -> void:
	if not FileAccess.file_exists(PATH):
		return
	var f := FileAccess.open(PATH, FileAccess.READ)
	if f == null:
		return
	var data: Variant = JSON.parse_string(f.get_as_text())
	if typeof(data) != TYPE_DICTIONARY:
		return
	var d: Dictionary = data
	plays = int(d.get("plays", 0))
	last_t = float(d.get("lastT", 0))
	muted = bool(d.get("muted", false))
	look_fails = int(d.get("lookFails", 0))
	look_ok = bool(d.get("lookOk", look_fails < 2))
	strength = float(d.get("strength", 1))

func save(t: float = last_t) -> void:
	last_t = t
	look_ok = look_fails < 2
	var f := FileAccess.open(PATH, FileAccess.WRITE)
	if f == null:
		return
	f.store_string(JSON.stringify({
		"plays": plays,
		"lastT": last_t,
		"muted": muted,
		"lookFails": look_fails,
		"lookOk": look_ok,
		"strength": strength,
	}))

func note_play(t: float) -> void:
	plays += 1
	save(t)

func note_look_fail() -> void:
	look_fails += 1
	strength = maxf(0.35, strength * 0.82)
	save()

func note_look_ok() -> void:
	strength = minf(1.0, strength + 0.04)
	save()

func should_use_look() -> bool:
	return look_fails < 2
