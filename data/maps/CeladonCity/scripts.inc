CeladonCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_OnTransition
	.byte 0

CeladonCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_CELADON_CITY
	end

CeladonCity_EventScript_LittleGirl::
	msgbox CeladonCity_Text_GotMyKoffingInCinnabar, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan1::
	lock
	msgbox CeladonCity_Text_GymIsGreatFullOfWomen
	release
	end

CeladonCity_EventScript_Woman::
	msgbox CeladonCity_Text_GameCornerIsBadForCitysImage, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan2::
	trainerbattle_single TRAINER_NPC_CELADON_OLDMAN, CeladonCity_Text_OldMan2Challenge, CeladonCity_Text_OldMan2Defeat
	msgbox CeladonCity_Text_BlewItAllAtSlots, MSGBOX_AUTOCLOSE
	end

CeladonCity_EventScript_SoftboiledTutor::
	goto EventScript_SoftboiledTutor
	end

CeladonCity_EventScript_FatMan::
	lock
	faceplayer
	msgbox CeladonCity_Text_MyTrustedPalPoliwrath
	closemessage
	applymovement LOCALID_CELADON_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath
	closemessage
	waitmoncry
	applymovement LOCALID_CELADON_POLIWRATH, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeladonCity_EventScript_RocketGrunt1::
	msgbox CeladonCity_Text_KeepOutOfTeamRocketsWay, MSGBOX_NPC
	end

CeladonCity_EventScript_RocketGrunt2::
	msgbox CeladonCity_Text_GetLostOrIllPunchYou, MSGBOX_NPC
	end

CeladonCity_EventScript_Boy::
	trainerbattle_single TRAINER_NPC_CELADON_BOY, CeladonCity_Text_BoyChallenge, CeladonCity_Text_BoyDefeat
	msgbox CeladonCity_Text_ScaldedTongueOnTea, MSGBOX_AUTOCLOSE
	end

CeladonCity_EventScript_SilphCoScientist::
	msgbox CeladonCity_Text_SomeoneStoleSilphScope, MSGBOX_NPC
	end

CeladonCity_EventScript_TrainerTips1::
	msgbox CeladonCity_Text_ExplainXAccuracyDireHit, MSGBOX_SIGN
	end

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_CitySign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_ERIKA, 0
	msgbox CeladonCity_Text_GymSign
	releaseall
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_DeptStoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips2::
	msgbox CeladonCity_Text_GuardSpecProtectsFromStatus, MSGBOX_SIGN
	end

CeladonCity_EventScript_PrizeExchangeSign::
	msgbox CeladonCity_Text_PrizeExchangeSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_Cynthia::
	lock
	faceplayer
	msgbox CeladonCity_Text_CynthiaIntro, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_CYNTHIA_CELADON, CeladonCity_Text_CynthiaChallenge, CeladonCity_Text_CynthiaDefeat
	msgbox CeladonCity_Text_CynthiaPostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_HIDE_CYNTHIA_AT_CELADON
	releaseall
	end

CeladonCity_Text_CynthiaIntro::
	.string "Ah, the Celadon Game Corner... it\n"
	.string "reminds me that battles aren't the\n"
	.string "only way to grow. Ready to face me?$"

CeladonCity_Text_CynthiaChallenge::
	.string "My Eevee evolved! Let's see what\n"
	.string "GLACEON can do!$"

CeladonCity_Text_CynthiaDefeat::
	.string "GLACEON and I need more training\n"
	.string "together still.$"

CeladonCity_Text_CynthiaPostBattle::
	.string "I found a HONEDGE near SILPH CO.\n"
	.string "It's from a different era entirely.\n"
	.string "Like a legend come to life!$"
