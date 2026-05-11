LavenderTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_OnTransition
	.byte 0

LavenderTown_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_LAVENDER_TOWN
	setvar VAR_MAP_SCENE_S_S_ANNE_2F_CORRIDOR, 1
	setflag FLAG_HIDE_SS_ANNE_RIVAL
	end

LavenderTown_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox LavenderTown_Text_DoYouBelieveInGhosts, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_EventScript_LittleGirlBelieve
	msgbox LavenderTown_Text_JustImaginingWhiteHand
	release
	end

LavenderTown_EventScript_LittleGirlBelieve::
	msgbox LavenderTown_Text_SoThereAreBelievers
	release
	end

LavenderTown_EventScript_WorkerM::
	trainerbattle_single TRAINER_NPC_LAVENDER_WORKERM, LavenderTown_Text_WorkerMChallenge, LavenderTown_Text_WorkerMDefeat
	msgbox LavenderTown_Text_TownKnownAsMonGraveSite, MSGBOX_AUTOCLOSE
	end

LavenderTown_EventScript_Boy::
	trainerbattle_single TRAINER_NPC_LAVENDER_BOY, LavenderTown_Text_BoyChallenge, LavenderTown_Text_BoyDefeat
	msgbox LavenderTown_Text_GhostsAppearedInTower, MSGBOX_AUTOCLOSE
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_TownSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SilphScopeNotice::
	msgbox LavenderTown_Text_SilphScopeNotice, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerHouseSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouse, MSGBOX_SIGN
	end

LavenderTown_EventScript_PokemonTowerSign::
	msgbox LavenderTown_Text_PokemonTowerSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_Cynthia::
	lock
	faceplayer
	msgbox LavenderTown_Text_CynthiaDialogue, MSGBOX_DEFAULT
	setflag FLAG_HIDE_CYNTHIA_AT_LAVENDER
	releaseall
	end

LavenderTown_Text_CynthiaDialogue::
	.string "This tower... it's just like the\n"
	.string "legends I've studied. Pokémon Tower\n"
	.string "holds Kanto's oldest mysteries.\p"
	.string "I spent the night reading the stone\n"
	.string "tablets here. The connection between\n"
	.string "humans and Pokémon runs so deep.\p"
	.string "I hope we meet again on your journey,\n"
	.string "trainer. You remind me of myself\n"
	.string "when I was starting out.$"
