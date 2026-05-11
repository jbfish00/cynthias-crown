SilphCo_7F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_7F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_7F_OnTransition
	.byte 0

SilphCo_7F_OnLoad::
	call_if_unset FLAG_SILPH_7F_DOOR_1, EventScript_Close7FDoor1
	call_if_unset FLAG_SILPH_7F_DOOR_2, EventScript_Close7FDoor2
	call_if_unset FLAG_SILPH_7F_DOOR_3, EventScript_Close7FDoor3
	end

SilphCo_7F_OnTransition::
	call_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_SetObjRocketsGone
	end

SilphCo_7F_EventScript_SetObjRocketsGone::
	setobjectmovementtype LOCALID_SILPH_CO_7F_WORKER_M2, MOVEMENT_TYPE_FACE_UP
	return

SilphCo_7F_EventScript_RivalTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	goto SilphCo_7F_EventScript_RivalScene
	end

SilphCo_7F_EventScript_RivalTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 1
	goto SilphCo_7F_EventScript_RivalScene
	end

SilphCo_7F_EventScript_RivalScene::
	textcolor NPC_TEXT_COLOR_MALE
	playbgm MUS_ENCOUNTER_RIVAL, 0
	applymovement LOCALID_SILPH_CO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_SILPH_CO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox SilphCo_7F_Text_RivalWhatKeptYou
	call_if_eq VAR_TEMP_1, 0, SilphCo_7F_EventScript_RivalApproachTop
	call_if_eq VAR_TEMP_1, 1, SilphCo_7F_EventScript_RivalApproachBottom
	msgbox SilphCo_7F_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_SILPH_CO_RIVAL
	call_if_eq VAR_STARTER_MON, 2, SilphCo_7F_EventScript_RivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, SilphCo_7F_EventScript_RivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, SilphCo_7F_EventScript_RivalCharmander
	msgbox SilphCo_7F_Text_RivalPostBattle
	closemessage
	playbgm MUS_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, SilphCo_7F_EventScript_RivalExitTop
	call_if_eq VAR_TEMP_1, 1, SilphCo_7F_EventScript_RivalExitBottom
	playse SE_WARP_IN
	fadedefaultbgm
	removeobject LOCALID_SILPH_CO_RIVAL
	waitse
	setvar VAR_MAP_SCENE_SILPH_CO_7F, 1
	releaseall
	end

SilphCo_7F_EventScript_RivalApproachTop::
	closemessage
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalApproachTop
	waitmovement 0
	return

SilphCo_7F_EventScript_RivalApproachBottom::
	return

SilphCo_7F_EventScript_RivalSquirtle::
SilphCo_7F_EventScript_RivalBulbasaur::
SilphCo_7F_EventScript_RivalCharmander::
	goto SilphCo_7F_Battle_RivalByType

SilphCo_7F_Battle_RivalByType::
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_NORMAL,   SilphCo_7F_Battle_Rival_Mankey
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_DARK,     SilphCo_7F_Battle_Rival_Mankey
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FIGHTING, SilphCo_7F_Battle_Rival_Pidgey
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FLYING,   SilphCo_7F_Battle_Rival_Omanyte
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_POISON,   SilphCo_7F_Battle_Rival_Trapinch
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_ELECTRIC, SilphCo_7F_Battle_Rival_Trapinch
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_GROUND,   SilphCo_7F_Battle_Rival_Squirtle
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_ROCK,     SilphCo_7F_Battle_Rival_Squirtle
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FIRE,     SilphCo_7F_Battle_Rival_Squirtle
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_BUG,      SilphCo_7F_Battle_Rival_Charmander
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_STEEL,    SilphCo_7F_Battle_Rival_Charmander
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_GRASS,    SilphCo_7F_Battle_Rival_Charmander
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_ICE,      SilphCo_7F_Battle_Rival_Charmander
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_GHOST,    SilphCo_7F_Battle_Rival_Zigzagoon
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_PSYCHIC,  SilphCo_7F_Battle_Rival_Zigzagoon
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_WATER,    SilphCo_7F_Battle_Rival_Bulbasaur
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_DRAGON,   SilphCo_7F_Battle_Rival_Swinub
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FAIRY,    SilphCo_7F_Battle_Rival_Honedge

SilphCo_7F_Battle_Rival_Mankey::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_COUNTER_MANKEY, SilphCo_7F_Text_RivalDefeat
	return
SilphCo_7F_Battle_Rival_Pidgey::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_COUNTER_PIDGEY, SilphCo_7F_Text_RivalDefeat
	return
SilphCo_7F_Battle_Rival_Omanyte::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_COUNTER_OMANYTE, SilphCo_7F_Text_RivalDefeat
	return
SilphCo_7F_Battle_Rival_Trapinch::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_COUNTER_TRAPINCH, SilphCo_7F_Text_RivalDefeat
	return
SilphCo_7F_Battle_Rival_Squirtle::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_SQUIRTLE, SilphCo_7F_Text_RivalDefeat
	return
SilphCo_7F_Battle_Rival_Charmander::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_CHARMANDER, SilphCo_7F_Text_RivalDefeat
	return
SilphCo_7F_Battle_Rival_Zigzagoon::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_COUNTER_ZIGZAGOON, SilphCo_7F_Text_RivalDefeat
	return
SilphCo_7F_Battle_Rival_Bulbasaur::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_BULBASAUR, SilphCo_7F_Text_RivalDefeat
	return
SilphCo_7F_Battle_Rival_Swinub::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_COUNTER_SWINUB, SilphCo_7F_Text_RivalDefeat
	return
SilphCo_7F_Battle_Rival_Honedge::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_COUNTER_HONEDGE, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalExitTop::
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalExitTop
	waitmovement 0
	return

SilphCo_7F_EventScript_RivalExitBottom::
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalExitBottom
	waitmovement 0
	return

SilphCo_7F_Movement_RivalApproachTop::
	walk_up
	step_end

SilphCo_7F_Movement_RivalExitTop::
	walk_right
	walk_right
	walk_right
	walk_up
	delay_16
	step_end

SilphCo_7F_Movement_RivalExitBottom::
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	delay_16
	step_end

SilphCo_7F_EventScript_LaprasGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_LAPRAS_FROM_SILPH, SilphCo_7F_EventScript_AlreadyGotLapras
	msgbox SilphCo_7F_Text_HaveMonForSavingUs
	setvar VAR_TEMP_1, SPECIES_LAPRAS
	givemon SPECIES_LAPRAS, 25
	goto_if_eq VAR_RESULT, 0, SilphCo_7F_EventScript_ReceiveLaprasParty
	goto_if_eq VAR_RESULT, 1, SilphCo_7F_EventScript_ReceiveLaprasPC
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
	release
	end

SilphCo_7F_EventScript_ReceiveLaprasParty::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message SilphCo_7F_Text_ObtainedLaprasFromEmployee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LAPRAS
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_7F_EventScript_EndReceiveLapras
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto SilphCo_7F_EventScript_EndReceiveLapras
	end

SilphCo_7F_EventScript_ReceiveLaprasPC::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message SilphCo_7F_Text_ObtainedLaprasFromEmployee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LAPRAS
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_7F_EventScript_LaprasTransferredToPC
	call EventScript_NameReceivedBoxMon
	goto SilphCo_7F_EventScript_LaprasTransferredToPC
	end

SilphCo_7F_EventScript_LaprasTransferredToPC::
	call EventScript_TransferredToPC
	goto SilphCo_7F_EventScript_EndReceiveLapras
	end

SilphCo_7F_EventScript_EndReceiveLapras::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox SilphCo_7F_Text_ExplainLapras
	setflag FLAG_GOT_LAPRAS_FROM_SILPH
	release
	end

SilphCo_7F_EventScript_AlreadyGotLapras::
	msgbox SilphCo_7F_Text_RocketBossWentToBoardroom
	release
	end

SilphCo_7F_EventScript_WorkerM1::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerM1RocketsGone
	msgbox SilphCo_7F_Text_RocketsAfterMasterBall
	release
	end

SilphCo_7F_EventScript_WorkerM1RocketsGone::
	msgbox SilphCo_7F_Text_CanceledMasterBallProject
	release
	end

SilphCo_7F_EventScript_WorkerM2::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerM2RocketsGone
	msgbox SilphCo_7F_Text_BadIfTeamRocketTookOver
	release
	end

SilphCo_7F_EventScript_WorkerM2RocketsGone::
	msgbox SilphCo_7F_Text_WowYouChasedOffTeamRocket
	release
	end

SilphCo_7F_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerFRocketsGone
	msgbox SilphCo_7F_Text_ReallyDangerousHere
	release
	end

SilphCo_7F_EventScript_WorkerFRocketsGone::
	msgbox SilphCo_7F_Text_ThankYouSoMuch
	release
	end

SilphCo_7F_EventScript_FloorSign::
	msgbox SilphCo_7F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_7F_EventScript_Joshua::
	trainerbattle_single TRAINER_SCIENTIST_JOSHUA, SilphCo_7F_Text_JoshuaIntro, SilphCo_7F_Text_JoshuaDefeat
	msgbox SilphCo_7F_Text_JoshuaPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_33, SilphCo_7F_Text_Grunt1Intro, SilphCo_7F_Text_Grunt1Defeat
	msgbox SilphCo_7F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_34, SilphCo_7F_Text_Grunt2Intro, SilphCo_7F_Text_Grunt2Defeat
	msgbox SilphCo_7F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_35, SilphCo_7F_Text_Grunt3Intro, SilphCo_7F_Text_Grunt3Defeat
	msgbox SilphCo_7F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end
