Route22_MapScripts::
	.byte 0

Route22_EventScript_EarlyRivalTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route22_EventScript_EarlyRival
	end

Route22_EventScript_EarlyRivalTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	setobjectxyperm LOCALID_ROUTE22_RIVAL, 25, 5
	goto Route22_EventScript_EarlyRival
	end

Route22_EventScript_EarlyRivalTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 2
	setobjectxyperm LOCALID_ROUTE22_RIVAL, 25, 5
	goto Route22_EventScript_EarlyRival
	end

Route22_EventScript_EarlyRival::
	textcolor NPC_TEXT_COLOR_MALE
	playbgm MUS_ENCOUNTER_RIVAL, 0
	addobject LOCALID_ROUTE22_RIVAL
	call_if_eq VAR_TEMP_1, 0, Route22_EventScript_EarlyRivalApproach
	call_if_eq VAR_TEMP_1, 1, Route22_EventScript_EarlyRivalApproach
	call_if_eq VAR_TEMP_1, 2, Route22_EventScript_EarlyRivalApproachBottom
	delay 6
	msgbox Route22_Text_EarlyRivalIntro
	call_if_eq VAR_STARTER_MON, 2, Route22_EventScript_EarlyRivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, Route22_EventScript_EarlyRivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, Route22_EventScript_EarlyRivalCharmander
	msgbox Route22_Text_EarlyRivalPostBattle
	closemessage
	delay 10
	playbgm MUS_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, Route22_EventScript_EarlyRivalExit
	call_if_eq VAR_TEMP_1, 1, Route22_EventScript_EarlyRivalExit
	call_if_eq VAR_TEMP_1, 2, Route22_EventScript_EarlyRivalExitBottom
	fadedefaultbgm
	removeobject LOCALID_ROUTE22_RIVAL
	setvar VAR_MAP_SCENE_ROUTE22, 2
	releaseall
	end

Route22_EventScript_EarlyRivalApproach::
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalApproach
	waitmovement 0
	return

Route22_EventScript_EarlyRivalApproachBottom::
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalApproachBottom
	applymovement LOCALID_PLAYER, Route22_Movement_PlayerFaceRival
	waitmovement 0
	return

Route22_EventScript_EarlyRivalSquirtle::
Route22_EventScript_EarlyRivalBulbasaur::
Route22_EventScript_EarlyRivalCharmander::
	goto Route22_Battle_EarlyRivalByType

Route22_Battle_EarlyRivalByType::
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_NORMAL,   Route22_Battle_EarlyRival_Mankey
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_DARK,     Route22_Battle_EarlyRival_Mankey
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FIGHTING, Route22_Battle_EarlyRival_Pidgey
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FLYING,   Route22_Battle_EarlyRival_Omanyte
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_POISON,   Route22_Battle_EarlyRival_Trapinch
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_ELECTRIC, Route22_Battle_EarlyRival_Trapinch
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_GROUND,   Route22_Battle_EarlyRival_Squirtle
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_ROCK,     Route22_Battle_EarlyRival_Squirtle
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FIRE,     Route22_Battle_EarlyRival_Squirtle
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_BUG,      Route22_Battle_EarlyRival_Charmander
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_STEEL,    Route22_Battle_EarlyRival_Charmander
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_GRASS,    Route22_Battle_EarlyRival_Charmander
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_ICE,      Route22_Battle_EarlyRival_Charmander
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_GHOST,    Route22_Battle_EarlyRival_Zigzagoon
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_PSYCHIC,  Route22_Battle_EarlyRival_Zigzagoon
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_WATER,    Route22_Battle_EarlyRival_Bulbasaur
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_DRAGON,   Route22_Battle_EarlyRival_Swinub
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FAIRY,    Route22_Battle_EarlyRival_Honedge

Route22_Battle_EarlyRival_Mankey::
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_COUNTER_MANKEY, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
	return
Route22_Battle_EarlyRival_Pidgey::
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_COUNTER_PIDGEY, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
	return
Route22_Battle_EarlyRival_Omanyte::
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_COUNTER_OMANYTE, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
	return
Route22_Battle_EarlyRival_Trapinch::
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_COUNTER_TRAPINCH, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
	return
Route22_Battle_EarlyRival_Squirtle::
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_SQUIRTLE, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
	return
Route22_Battle_EarlyRival_Charmander::
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_CHARMANDER, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
	return
Route22_Battle_EarlyRival_Zigzagoon::
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_COUNTER_ZIGZAGOON, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
	return
Route22_Battle_EarlyRival_Bulbasaur::
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_BULBASAUR, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
	return
Route22_Battle_EarlyRival_Swinub::
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_COUNTER_SWINUB, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
	return
Route22_Battle_EarlyRival_Honedge::
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_COUNTER_HONEDGE, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
	return

Route22_EventScript_EarlyRivalExit::
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_EarlyRivalExit
	waitmovement 0
	return

Route22_EventScript_EarlyRivalExitBottom::
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_EarlyRivalExitBottom
	waitmovement 0
	return

Route22_Movement_UnusedRivalExit:: @ 8
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route22_Movement_EarlyRivalExit::
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route22_Movement_EarlyRivalExitBottom::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route22_Movement_RivalApproach::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route22_Movement_RivalApproachBottom::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

Route22_Movement_PlayerFaceRival::
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_up
	step_end

Route22_EventScript_LateRivalTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route22_EventScript_LateRival
	end

Route22_EventScript_LateRivalTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	setobjectxyperm LOCALID_ROUTE22_RIVAL, 25, 5
	goto Route22_EventScript_LateRival
	end

Route22_EventScript_LateRivalTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 2
	setobjectxyperm LOCALID_ROUTE22_RIVAL, 25, 5
	goto Route22_EventScript_LateRival
	end

Route22_EventScript_LateRival::
	textcolor NPC_TEXT_COLOR_MALE
	playbgm MUS_ENCOUNTER_RIVAL, 0
	addobject LOCALID_ROUTE22_RIVAL
	call_if_eq VAR_TEMP_1, 0, Route22_EventScript_LateRivalApproach
	call_if_eq VAR_TEMP_1, 1, Route22_EventScript_LateRivalApproach
	call_if_eq VAR_TEMP_1, 2, Route22_EventScript_LateRivalApproachBottom
	msgbox Route22_Text_LateRivalIntro
	setvar VAR_LAST_TALKED, LOCALID_ROUTE22_RIVAL
	call_if_eq VAR_STARTER_MON, 2, Route22_EventScript_LateRivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, Route22_EventScript_LateRivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, Route22_EventScript_LateRivalCharmander
	msgbox Route22_Text_LateRivalPostBattle
	closemessage
	delay 10
	playbgm MUS_RIVAL_EXIT, 0
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_LateRivalExit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_ROUTE22_RIVAL
	setvar VAR_MAP_SCENE_ROUTE22, 4
	releaseall
	end

Route22_EventScript_LateRivalApproach::
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalApproach
	waitmovement 0
	return

Route22_EventScript_LateRivalApproachBottom::
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalApproachBottom
	applymovement LOCALID_PLAYER, Route22_Movement_PlayerFaceRival
	waitmovement 0
	return

Route22_EventScript_LateRivalSquirtle::
Route22_EventScript_LateRivalBulbasaur::
Route22_EventScript_LateRivalCharmander::
	goto Route22_Battle_LateRivalByType

Route22_Battle_LateRivalByType::
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_NORMAL,   Route22_Battle_LateRival_Mankey
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_DARK,     Route22_Battle_LateRival_Mankey
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FIGHTING, Route22_Battle_LateRival_Pidgey
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FLYING,   Route22_Battle_LateRival_Omanyte
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_POISON,   Route22_Battle_LateRival_Trapinch
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_ELECTRIC, Route22_Battle_LateRival_Trapinch
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_GROUND,   Route22_Battle_LateRival_Squirtle
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_ROCK,     Route22_Battle_LateRival_Squirtle
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FIRE,     Route22_Battle_LateRival_Squirtle
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_BUG,      Route22_Battle_LateRival_Charmander
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_STEEL,    Route22_Battle_LateRival_Charmander
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_GRASS,    Route22_Battle_LateRival_Charmander
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_ICE,      Route22_Battle_LateRival_Charmander
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_GHOST,    Route22_Battle_LateRival_Zigzagoon
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_PSYCHIC,  Route22_Battle_LateRival_Zigzagoon
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_WATER,    Route22_Battle_LateRival_Bulbasaur
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_DRAGON,   Route22_Battle_LateRival_Swinub
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FAIRY,    Route22_Battle_LateRival_Honedge

Route22_Battle_LateRival_Mankey::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_COUNTER_MANKEY, Route22_Text_LateRivalDefeat
	return
Route22_Battle_LateRival_Pidgey::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_COUNTER_PIDGEY, Route22_Text_LateRivalDefeat
	return
Route22_Battle_LateRival_Omanyte::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_COUNTER_OMANYTE, Route22_Text_LateRivalDefeat
	return
Route22_Battle_LateRival_Trapinch::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_COUNTER_TRAPINCH, Route22_Text_LateRivalDefeat
	return
Route22_Battle_LateRival_Squirtle::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_SQUIRTLE, Route22_Text_LateRivalDefeat
	return
Route22_Battle_LateRival_Charmander::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_CHARMANDER, Route22_Text_LateRivalDefeat
	return
Route22_Battle_LateRival_Zigzagoon::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_COUNTER_ZIGZAGOON, Route22_Text_LateRivalDefeat
	return
Route22_Battle_LateRival_Bulbasaur::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_BULBASAUR, Route22_Text_LateRivalDefeat
	return
Route22_Battle_LateRival_Swinub::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_COUNTER_SWINUB, Route22_Text_LateRivalDefeat
	return
Route22_Battle_LateRival_Honedge::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_COUNTER_HONEDGE, Route22_Text_LateRivalDefeat
	return

Route22_Movement_LateRivalExit::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route22_EventScript_LeagueGateSign::
	msgbox Route22_Text_LeagueGateSign, MSGBOX_SIGN
	end
