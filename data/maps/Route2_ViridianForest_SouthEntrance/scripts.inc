Route2_ViridianForest_SouthEntrance_MapScripts::
	.byte 0

Route2_ViridianForest_SouthEntrance_EventScript_Woman1::
	msgbox Route2_ViridianForest_SouthEntrance_Text_ForestIsMaze, MSGBOX_NPC
	end

Route2_ViridianForest_SouthEntrance_EventScript_Woman2::
	msgbox Route2_ViridianForest_SouthEntrance_Text_RattataHasWickedBite, MSGBOX_NPC
	end

Route2_ViridianForest_SouthEntrance_EventScript_Steven::
	lock
	faceplayer
	msgbox Route2_ViridianForest_SouthEntrance_Text_StevenIntro, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_CYNTHIA_VIRIDIAN, Route2_ViridianForest_SouthEntrance_Text_StevenChallenge, Route2_ViridianForest_SouthEntrance_Text_StevenDefeat
	msgbox Route2_ViridianForest_SouthEntrance_Text_StevenPostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_HIDE_CYNTHIA_AT_VIRIDIAN
	release
	end

Route2_ViridianForest_SouthEntrance_Text_StevenIntro::
	.string "Ah, a trainer! I've just started\n"
	.string "my Kanto journey. Care to test\n"
	.string "what I've learned so far?$"

Route2_ViridianForest_SouthEntrance_Text_StevenChallenge::
	.string "Let's see what Kanto has taught me!$"

Route2_ViridianForest_SouthEntrance_Text_StevenDefeat::
	.string "Impressive! You're quite skilled.$"

Route2_ViridianForest_SouthEntrance_Text_StevenPostBattle::
	.string "My name is STEVEN. I'm a trainer\n"
	.string "from Hoenn, traveling through Kanto.\n"
	.string "Let's battle again someday!$"
