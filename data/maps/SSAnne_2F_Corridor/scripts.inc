SSAnne_2F_Corridor_MapScripts::
	.byte 0

SSAnne_2F_Corridor_EventScript_RivalTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto SSAnne_2F_Corridor_EventScript_RivalTrigger
	end

SSAnne_2F_Corridor_EventScript_RivalTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	goto SSAnne_2F_Corridor_EventScript_RivalTrigger
	end

SSAnne_2F_Corridor_EventScript_RivalTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	goto SSAnne_2F_Corridor_EventScript_RivalTrigger
	end

SSAnne_2F_Corridor_EventScript_RivalTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	playse SE_EXIT
	delay 5
	playbgm MUS_ENCOUNTER_RIVAL, 0
	addobject LOCALID_SS_ANNE_RIVAL
	delay 10
	applymovement LOCALID_SS_ANNE_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 20
	call_if_eq VAR_TEMP_1, 0, SSAnne_2F_Corridor_EventScript_RivalApproachLeft
	call_if_eq VAR_TEMP_1, 1, SSAnne_2F_Corridor_EventScript_RivalApproachMid
	call_if_eq VAR_TEMP_1, 2, SSAnne_2F_Corridor_EventScript_RivalApproachRight
	msgbox SSAnne_2F_Corridor_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_SS_ANNE_RIVAL
	call_if_eq VAR_STARTER_MON, 2, SSAnne_2F_Corridor_EventScript_RivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, SSAnne_2F_Corridor_EventScript_RivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, SSAnne_2F_Corridor_EventScript_RivalCharmander
	msgbox SSAnne_2F_Corridor_Text_RivalPostBattle
	closemessage
	delay 10
	playbgm MUS_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, SSAnne_2F_Corridor_EventScript_RivalExitLeft
	call_if_eq VAR_TEMP_1, 1, SSAnne_2F_Corridor_EventScript_RivalExitMid
	call_if_eq VAR_TEMP_1, 2, SSAnne_2F_Corridor_EventScript_RivalExitRight
	fadedefaultbgm
	removeobject LOCALID_SS_ANNE_RIVAL
	setvar VAR_MAP_SCENE_S_S_ANNE_2F_CORRIDOR, 1
	releaseall
	end

SSAnne_2F_Corridor_EventScript_RivalApproachLeft::
	applymovement LOCALID_SS_ANNE_RIVAL, SSAnne_2F_Corridor_Movement_RivalApproachLeft
	waitmovement 0
	return

SSAnne_2F_Corridor_EventScript_RivalApproachMid::
	applymovement LOCALID_SS_ANNE_RIVAL, SSAnne_2F_Corridor_Movement_RivalApproachMid
	applymovement LOCALID_PLAYER, SSAnne_2F_Corridor_Movement_PlayerFaceRivalMid
	waitmovement 0
	return

SSAnne_2F_Corridor_EventScript_RivalApproachRight::
	applymovement LOCALID_PLAYER, SSAnne_2F_Corridor_Movement_PlayerFaceRivalRight
	applymovement LOCALID_SS_ANNE_RIVAL, SSAnne_2F_Corridor_Movement_RivalApproachRight
	waitmovement 0
	return

SSAnne_2F_Corridor_EventScript_RivalSquirtle::
SSAnne_2F_Corridor_EventScript_RivalBulbasaur::
SSAnne_2F_Corridor_EventScript_RivalCharmander::
	goto SSAnne_2F_Corridor_Battle_RivalByType

SSAnne_2F_Corridor_Battle_RivalByType::
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_NORMAL,   SSAnne_2F_Corridor_Battle_Rival_Mankey
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_DARK,     SSAnne_2F_Corridor_Battle_Rival_Mankey
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FIGHTING, SSAnne_2F_Corridor_Battle_Rival_Pidgey
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FLYING,   SSAnne_2F_Corridor_Battle_Rival_Omanyte
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_POISON,   SSAnne_2F_Corridor_Battle_Rival_Trapinch
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_ELECTRIC, SSAnne_2F_Corridor_Battle_Rival_Trapinch
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_GROUND,   SSAnne_2F_Corridor_Battle_Rival_Squirtle
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_ROCK,     SSAnne_2F_Corridor_Battle_Rival_Squirtle
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FIRE,     SSAnne_2F_Corridor_Battle_Rival_Squirtle
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_BUG,      SSAnne_2F_Corridor_Battle_Rival_Charmander
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_STEEL,    SSAnne_2F_Corridor_Battle_Rival_Charmander
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_GRASS,    SSAnne_2F_Corridor_Battle_Rival_Charmander
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_ICE,      SSAnne_2F_Corridor_Battle_Rival_Charmander
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_GHOST,    SSAnne_2F_Corridor_Battle_Rival_Zigzagoon
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_PSYCHIC,  SSAnne_2F_Corridor_Battle_Rival_Zigzagoon
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_WATER,    SSAnne_2F_Corridor_Battle_Rival_Bulbasaur
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_DRAGON,   SSAnne_2F_Corridor_Battle_Rival_Swinub
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FAIRY,    SSAnne_2F_Corridor_Battle_Rival_Honedge

SSAnne_2F_Corridor_Battle_Rival_Mankey::
	trainerbattle_no_intro TRAINER_RIVAL_SS_ANNE_COUNTER_MANKEY, SSAnne_2F_Corridor_Text_RivalDefeat
	return
SSAnne_2F_Corridor_Battle_Rival_Pidgey::
	trainerbattle_no_intro TRAINER_RIVAL_SS_ANNE_COUNTER_PIDGEY, SSAnne_2F_Corridor_Text_RivalDefeat
	return
SSAnne_2F_Corridor_Battle_Rival_Omanyte::
	trainerbattle_no_intro TRAINER_RIVAL_SS_ANNE_COUNTER_OMANYTE, SSAnne_2F_Corridor_Text_RivalDefeat
	return
SSAnne_2F_Corridor_Battle_Rival_Trapinch::
	trainerbattle_no_intro TRAINER_RIVAL_SS_ANNE_COUNTER_TRAPINCH, SSAnne_2F_Corridor_Text_RivalDefeat
	return
SSAnne_2F_Corridor_Battle_Rival_Squirtle::
	trainerbattle_no_intro TRAINER_RIVAL_SS_ANNE_SQUIRTLE, SSAnne_2F_Corridor_Text_RivalDefeat
	return
SSAnne_2F_Corridor_Battle_Rival_Charmander::
	trainerbattle_no_intro TRAINER_RIVAL_SS_ANNE_CHARMANDER, SSAnne_2F_Corridor_Text_RivalDefeat
	return
SSAnne_2F_Corridor_Battle_Rival_Zigzagoon::
	trainerbattle_no_intro TRAINER_RIVAL_SS_ANNE_COUNTER_ZIGZAGOON, SSAnne_2F_Corridor_Text_RivalDefeat
	return
SSAnne_2F_Corridor_Battle_Rival_Bulbasaur::
	trainerbattle_no_intro TRAINER_RIVAL_SS_ANNE_BULBASAUR, SSAnne_2F_Corridor_Text_RivalDefeat
	return
SSAnne_2F_Corridor_Battle_Rival_Swinub::
	trainerbattle_no_intro TRAINER_RIVAL_SS_ANNE_COUNTER_SWINUB, SSAnne_2F_Corridor_Text_RivalDefeat
	return
SSAnne_2F_Corridor_Battle_Rival_Honedge::
	trainerbattle_no_intro TRAINER_RIVAL_SS_ANNE_COUNTER_HONEDGE, SSAnne_2F_Corridor_Text_RivalDefeat
	return

SSAnne_2F_Corridor_EventScript_RivalExitLeft::
	applymovement LOCALID_SS_ANNE_RIVAL, SSAnne_2F_Corridor_Movement_RivalExitLeft
	waitmovement 0
	return

SSAnne_2F_Corridor_EventScript_RivalExitMid::
	applymovement LOCALID_SS_ANNE_RIVAL, SSAnne_2F_Corridor_Movement_RivalExitMid
	waitmovement 0
	return

SSAnne_2F_Corridor_EventScript_RivalExitRight::
	applymovement LOCALID_SS_ANNE_RIVAL, SSAnne_2F_Corridor_Movement_RivalExitRight
	waitmovement 0
	return

SSAnne_2F_Corridor_Movement_PlayerFaceRivalRight::
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SSAnne_2F_Corridor_Movement_PlayerFaceRivalMid::
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SSAnne_2F_Corridor_Movement_RivalApproachLeft::
	walk_down
	walk_down
	walk_down
	step_end

SSAnne_2F_Corridor_Movement_RivalApproachMid::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

SSAnne_2F_Corridor_Movement_RivalApproachRight::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	delay_4
	step_end

SSAnne_2F_Corridor_Movement_RivalExitLeft::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SSAnne_2F_Corridor_Movement_RivalExitMid::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SSAnne_2F_Corridor_Movement_RivalExitRight::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SSAnne_2F_Corridor_EventScript_Sailor::
	msgbox SSAnne_2F_Corridor_Text_ThisShipIsLuxuryLiner, MSGBOX_NPC
	end
