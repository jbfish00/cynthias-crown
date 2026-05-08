TypeShrine_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TypeShrine_OnWarp
	.byte 0

TypeShrine_OnWarp::
	map_script_2 VAR_TYPE_SHRINE_SCENE, 0, TypeShrine_EventScript_StartScene
	.2byte 0

TypeShrine_EventScript_StartScene::
	lockall
	msgbox TypeShrine_Text_WelcomeToShrine, MSGBOX_DEFAULT
	msgbox TypeShrine_Text_ChooseYourType, MSGBOX_DEFAULT

TypeShrine_EventScript_TypeSelectionLoop::
	multichoice 0, 0, MULTICHOICE_TYPE_SELECTION, FALSE
	setvar VAR_CHOSEN_TYPE, VAR_RESULT
	call TypeShrine_EventScript_ShowTypeDescription
	msgbox TypeShrine_Text_ConfirmChoice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TypeShrine_EventScript_TypeSelectionLoop
	goto TypeShrine_EventScript_GiveStarter

TypeShrine_EventScript_ShrineKeeper::
	lock
	faceplayer
	msgbox TypeShrine_Text_YouHaveChosen, MSGBOX_DEFAULT
	release
	end

TypeShrine_EventScript_ShowTypeDescription::
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_NORMAL,   TypeShrine_ShowDesc_Normal
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FIGHTING, TypeShrine_ShowDesc_Fighting
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FLYING,   TypeShrine_ShowDesc_Flying
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_POISON,   TypeShrine_ShowDesc_Poison
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_GROUND,   TypeShrine_ShowDesc_Ground
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_ROCK,     TypeShrine_ShowDesc_Rock
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_BUG,      TypeShrine_ShowDesc_Bug
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_GHOST,    TypeShrine_ShowDesc_Ghost
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_STEEL,    TypeShrine_ShowDesc_Steel
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FIRE,     TypeShrine_ShowDesc_Fire
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_WATER,    TypeShrine_ShowDesc_Water
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_GRASS,    TypeShrine_ShowDesc_Grass
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_ELECTRIC, TypeShrine_ShowDesc_Electric
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_PSYCHIC,  TypeShrine_ShowDesc_Psychic
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_ICE,      TypeShrine_ShowDesc_Ice
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_DRAGON,   TypeShrine_ShowDesc_Dragon
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_DARK,     TypeShrine_ShowDesc_Dark
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FAIRY,    TypeShrine_ShowDesc_Fairy
	return

TypeShrine_ShowDesc_Normal::
	msgbox TypeShrine_Text_DescNormal, MSGBOX_DEFAULT
	return

TypeShrine_ShowDesc_Fighting::
	msgbox TypeShrine_Text_DescFighting, MSGBOX_DEFAULT
	return

TypeShrine_ShowDesc_Flying::
	msgbox TypeShrine_Text_DescFlying, MSGBOX_DEFAULT
	return

TypeShrine_ShowDesc_Poison::
	msgbox TypeShrine_Text_DescPoison, MSGBOX_DEFAULT
	return

TypeShrine_ShowDesc_Ground::
	msgbox TypeShrine_Text_DescGround, MSGBOX_DEFAULT
	return

TypeShrine_ShowDesc_Rock::
	msgbox TypeShrine_Text_DescRock, MSGBOX_DEFAULT
	return

TypeShrine_ShowDesc_Bug::
	msgbox TypeShrine_Text_DescBug, MSGBOX_DEFAULT
	return

TypeShrine_ShowDesc_Ghost::
	msgbox TypeShrine_Text_DescGhost, MSGBOX_DEFAULT
	return

TypeShrine_ShowDesc_Steel::
	msgbox TypeShrine_Text_DescSteel, MSGBOX_DEFAULT
	return

TypeShrine_ShowDesc_Fire::
	msgbox TypeShrine_Text_DescFire, MSGBOX_DEFAULT
	return

TypeShrine_ShowDesc_Water::
	msgbox TypeShrine_Text_DescWater, MSGBOX_DEFAULT
	return

TypeShrine_ShowDesc_Grass::
	msgbox TypeShrine_Text_DescGrass, MSGBOX_DEFAULT
	return

TypeShrine_ShowDesc_Electric::
	msgbox TypeShrine_Text_DescElectric, MSGBOX_DEFAULT
	return

TypeShrine_ShowDesc_Psychic::
	msgbox TypeShrine_Text_DescPsychic, MSGBOX_DEFAULT
	return

TypeShrine_ShowDesc_Ice::
	msgbox TypeShrine_Text_DescIce, MSGBOX_DEFAULT
	return

TypeShrine_ShowDesc_Dragon::
	msgbox TypeShrine_Text_DescDragon, MSGBOX_DEFAULT
	return

TypeShrine_ShowDesc_Dark::
	msgbox TypeShrine_Text_DescDark, MSGBOX_DEFAULT
	return

TypeShrine_ShowDesc_Fairy::
	msgbox TypeShrine_Text_DescFairy, MSGBOX_DEFAULT
	return

TypeShrine_EventScript_GiveStarter::
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_NORMAL,   TypeShrine_EventScript_GiveNormal
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FIGHTING, TypeShrine_EventScript_GiveFighting
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FLYING,   TypeShrine_EventScript_GiveFlying
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_POISON,   TypeShrine_EventScript_GivePoison
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_GROUND,   TypeShrine_EventScript_GiveGround
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_ROCK,     TypeShrine_EventScript_GiveRock
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_BUG,      TypeShrine_EventScript_GiveBug
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_GHOST,    TypeShrine_EventScript_GiveGhost
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_STEEL,    TypeShrine_EventScript_GiveSteel
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FIRE,     TypeShrine_EventScript_GiveFire
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_WATER,    TypeShrine_EventScript_GiveWater
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_GRASS,    TypeShrine_EventScript_GiveGrass
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_ELECTRIC, TypeShrine_EventScript_GiveElectric
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_PSYCHIC,  TypeShrine_EventScript_GivePsychic
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_ICE,      TypeShrine_EventScript_GiveIce
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_DRAGON,   TypeShrine_EventScript_GiveDragon
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_DARK,     TypeShrine_EventScript_GiveDark
	goto_if_eq VAR_CHOSEN_TYPE, TYPE_FAIRY,    TypeShrine_EventScript_GiveFairy
	end

TypeShrine_EventScript_GiveNormal::
	givemon SPECIES_PORYGON, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveFighting::
	givemon SPECIES_MANKEY, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveGround::
	givemon SPECIES_TRAPINCH, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveGhost::
	givemon SPECIES_GASTLY, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveElectric::
	givemon SPECIES_SHINX, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveIce::
	givemon SPECIES_SWINUB, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GivePsychic::
	givemon SPECIES_ABRA, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveDragon::
	givemon SPECIES_AXEW, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveDark::
	givemon SPECIES_GALARIAN_ZIGZAGOON, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveSteel::
	givemon SPECIES_HONEDGE, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveFairy::
	givemon SPECIES_TOGEPI, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GivePoison::
	msgbox TypeShrine_Text_PoisonChoose, MSGBOX_DEFAULT
	multichoice 0, 0, MULTICHOICE_NIDORAN_CHOICE, FALSE
	goto_if_eq VAR_RESULT, 0, TypeShrine_EventScript_GiveNidoranM
	givemon SPECIES_NIDORAN_F, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveNidoranM::
	givemon SPECIES_NIDORAN_M, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveFlying::
	msgbox TypeShrine_Text_FlyingChoose, MSGBOX_DEFAULT
	multichoice 0, 0, MULTICHOICE_FLYING_CHOICE, FALSE
	setvar VAR_CHOSEN_STARTER, VAR_RESULT
	goto_if_eq VAR_CHOSEN_STARTER, 0, TypeShrine_EventScript_GivePidgey
	goto_if_eq VAR_CHOSEN_STARTER, 1, TypeShrine_EventScript_GiveSpearow
	givemon SPECIES_DODUO, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GivePidgey::
	givemon SPECIES_PIDGEY, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveSpearow::
	givemon SPECIES_SPEAROW, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveBug::
	msgbox TypeShrine_Text_BugChoose, MSGBOX_DEFAULT
	multichoice 0, 0, MULTICHOICE_BUG_CHOICE, FALSE
	setvar VAR_CHOSEN_STARTER, VAR_RESULT
	goto_if_eq VAR_CHOSEN_STARTER, 0, TypeShrine_EventScript_GivePinsir
	goto_if_eq VAR_CHOSEN_STARTER, 1, TypeShrine_EventScript_GiveScyther
	givemon SPECIES_HERACROSS, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GivePinsir::
	givemon SPECIES_PINSIR, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveScyther::
	givemon SPECIES_SCYTHER, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveRock::
	msgbox TypeShrine_Text_RockChoose, MSGBOX_DEFAULT
	multichoice 0, 0, MULTICHOICE_ROCK_CHOICE, FALSE
	setvar VAR_CHOSEN_STARTER, VAR_RESULT
	goto_if_eq VAR_CHOSEN_STARTER, 0, TypeShrine_EventScript_GiveOmanyte
	goto_if_eq VAR_CHOSEN_STARTER, 1, TypeShrine_EventScript_GiveKabuto
	givemon SPECIES_AERODACTYL, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveOmanyte::
	givemon SPECIES_OMANYTE, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveKabuto::
	givemon SPECIES_KABUTO, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveFire::
	msgbox TypeShrine_Text_FireChoose, MSGBOX_DEFAULT
	multichoice 0, 0, MULTICHOICE_FIRE_CHOICE, FALSE
	setvar VAR_CHOSEN_STARTER, VAR_RESULT
	goto_if_eq VAR_CHOSEN_STARTER, 0, TypeShrine_EventScript_GiveCharmander
	goto_if_eq VAR_CHOSEN_STARTER, 1, TypeShrine_EventScript_GiveCyndaquil
	givemon SPECIES_TORCHIC, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveCharmander::
	givemon SPECIES_CHARMANDER, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveCyndaquil::
	givemon SPECIES_CYNDAQUIL, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveWater::
	msgbox TypeShrine_Text_WaterChoose, MSGBOX_DEFAULT
	multichoice 0, 0, MULTICHOICE_WATER_CHOICE, FALSE
	setvar VAR_CHOSEN_STARTER, VAR_RESULT
	goto_if_eq VAR_CHOSEN_STARTER, 0, TypeShrine_EventScript_GiveSquirtle
	goto_if_eq VAR_CHOSEN_STARTER, 1, TypeShrine_EventScript_GiveTotodile
	givemon SPECIES_MUDKIP, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveSquirtle::
	givemon SPECIES_SQUIRTLE, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveTotodile::
	givemon SPECIES_TOTODILE, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveGrass::
	msgbox TypeShrine_Text_GrassChoose, MSGBOX_DEFAULT
	multichoice 0, 0, MULTICHOICE_GRASS_CHOICE, FALSE
	setvar VAR_CHOSEN_STARTER, VAR_RESULT
	goto_if_eq VAR_CHOSEN_STARTER, 0, TypeShrine_EventScript_GiveBulbasaur
	goto_if_eq VAR_CHOSEN_STARTER, 1, TypeShrine_EventScript_GiveChikorita
	givemon SPECIES_TREECKO, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveBulbasaur::
	givemon SPECIES_BULBASAUR, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_GiveChikorita::
	givemon SPECIES_CHIKORITA, 5
	goto TypeShrine_EventScript_StarterGiven

TypeShrine_EventScript_StarterGiven::
	playfanfare MUS_LEVEL_UP
	waitfanfare
	msgbox TypeShrine_Text_StarterGiven, MSGBOX_DEFAULT
	msgbox TypeShrine_Text_YourJourneyBegins, MSGBOX_DEFAULT
	setflag FLAG_CHOSE_PLAYER_TYPE
	setvar VAR_TYPE_SHRINE_SCENE, 1
	releaseall
	warp MAP_PALLET_TOWN_PLAYERS_HOUSE_2F, 5, 7
	waitstate
	end
