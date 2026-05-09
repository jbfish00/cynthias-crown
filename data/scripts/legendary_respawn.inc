LegendaryRespawnScript::
    @ Gen 1
    goto_if_set FLAG_LEGENDARY_ARTICUNO_CAUGHT, LegendaryRespawn_SkipArticuno
    clearflag FLAG_LEGENDARY_ARTICUNO_BATTLED
LegendaryRespawn_SkipArticuno:
    goto_if_set FLAG_LEGENDARY_ZAPDOS_CAUGHT, LegendaryRespawn_SkipZapdos
    clearflag FLAG_LEGENDARY_ZAPDOS_BATTLED
LegendaryRespawn_SkipZapdos:
    goto_if_set FLAG_LEGENDARY_MOLTRES_CAUGHT, LegendaryRespawn_SkipMoltres
    clearflag FLAG_LEGENDARY_MOLTRES_BATTLED
LegendaryRespawn_SkipMoltres:
    goto_if_set FLAG_LEGENDARY_MEWTWO_CAUGHT, LegendaryRespawn_SkipMewtwo
    clearflag FLAG_LEGENDARY_MEWTWO_BATTLED
LegendaryRespawn_SkipMewtwo:
    goto_if_set FLAG_LEGENDARY_MEW_CAUGHT, LegendaryRespawn_SkipMew
    clearflag FLAG_LEGENDARY_MEW_BATTLED
LegendaryRespawn_SkipMew:

    @ Gen 2
    goto_if_set FLAG_LEGENDARY_RAIKOU_CAUGHT, LegendaryRespawn_SkipRaikou
    clearflag FLAG_LEGENDARY_RAIKOU_BATTLED
LegendaryRespawn_SkipRaikou:
    goto_if_set FLAG_LEGENDARY_ENTEI_CAUGHT, LegendaryRespawn_SkipEntei
    clearflag FLAG_LEGENDARY_ENTEI_BATTLED
LegendaryRespawn_SkipEntei:
    goto_if_set FLAG_LEGENDARY_SUICUNE_CAUGHT, LegendaryRespawn_SkipSuicune
    clearflag FLAG_LEGENDARY_SUICUNE_BATTLED
LegendaryRespawn_SkipSuicune:
    goto_if_set FLAG_LEGENDARY_LUGIA_CAUGHT, LegendaryRespawn_SkipLugia
    clearflag FLAG_LEGENDARY_LUGIA_BATTLED
LegendaryRespawn_SkipLugia:
    goto_if_set FLAG_LEGENDARY_HO_OH_CAUGHT, LegendaryRespawn_SkipHoOh
    clearflag FLAG_LEGENDARY_HO_OH_BATTLED
LegendaryRespawn_SkipHoOh:
    goto_if_set FLAG_LEGENDARY_CELEBI_CAUGHT, LegendaryRespawn_SkipCelebi
    clearflag FLAG_LEGENDARY_CELEBI_BATTLED
LegendaryRespawn_SkipCelebi:

    @ Gen 3
    goto_if_set FLAG_LEGENDARY_REGIROCK_CAUGHT, LegendaryRespawn_SkipRegirock
    clearflag FLAG_LEGENDARY_REGIROCK_BATTLED
LegendaryRespawn_SkipRegirock:
    goto_if_set FLAG_LEGENDARY_REGICE_CAUGHT, LegendaryRespawn_SkipRegice
    clearflag FLAG_LEGENDARY_REGICE_BATTLED
LegendaryRespawn_SkipRegice:
    goto_if_set FLAG_LEGENDARY_REGISTEEL_CAUGHT, LegendaryRespawn_SkipRegisteel
    clearflag FLAG_LEGENDARY_REGISTEEL_BATTLED
LegendaryRespawn_SkipRegisteel:
    goto_if_set FLAG_LEGENDARY_LATIAS_CAUGHT, LegendaryRespawn_SkipLatias
    clearflag FLAG_LEGENDARY_LATIAS_BATTLED
LegendaryRespawn_SkipLatias:
    goto_if_set FLAG_LEGENDARY_LATIOS_CAUGHT, LegendaryRespawn_SkipLatios
    clearflag FLAG_LEGENDARY_LATIOS_BATTLED
LegendaryRespawn_SkipLatios:
    goto_if_set FLAG_LEGENDARY_KYOGRE_CAUGHT, LegendaryRespawn_SkipKyogre
    clearflag FLAG_LEGENDARY_KYOGRE_BATTLED
LegendaryRespawn_SkipKyogre:
    goto_if_set FLAG_LEGENDARY_GROUDON_CAUGHT, LegendaryRespawn_SkipGroudon
    clearflag FLAG_LEGENDARY_GROUDON_BATTLED
LegendaryRespawn_SkipGroudon:
    goto_if_set FLAG_LEGENDARY_RAYQUAZA_CAUGHT, LegendaryRespawn_SkipRayquaza
    clearflag FLAG_LEGENDARY_RAYQUAZA_BATTLED
LegendaryRespawn_SkipRayquaza:
    goto_if_set FLAG_LEGENDARY_JIRACHI_CAUGHT, LegendaryRespawn_SkipJirachi
    clearflag FLAG_LEGENDARY_JIRACHI_BATTLED
LegendaryRespawn_SkipJirachi:
    goto_if_set FLAG_LEGENDARY_DEOXYS_CAUGHT, LegendaryRespawn_SkipDeoxys
    clearflag FLAG_LEGENDARY_DEOXYS_BATTLED
LegendaryRespawn_SkipDeoxys:

    @ Gen 4 legendaries (added in Step 5)
    goto_if_set FLAG_LEGENDARY_UXIE_CAUGHT, LegendaryRespawn_SkipUxie
    clearflag FLAG_LEGENDARY_UXIE_BATTLED
LegendaryRespawn_SkipUxie:
    goto_if_set FLAG_LEGENDARY_MESPRIT_CAUGHT, LegendaryRespawn_SkipMesprit
    clearflag FLAG_LEGENDARY_MESPRIT_BATTLED
LegendaryRespawn_SkipMesprit:
    goto_if_set FLAG_LEGENDARY_AZELF_CAUGHT, LegendaryRespawn_SkipAzelf
    clearflag FLAG_LEGENDARY_AZELF_BATTLED
LegendaryRespawn_SkipAzelf:
    goto_if_set FLAG_LEGENDARY_DIALGA_CAUGHT, LegendaryRespawn_SkipDialga
    clearflag FLAG_LEGENDARY_DIALGA_BATTLED
LegendaryRespawn_SkipDialga:
    goto_if_set FLAG_LEGENDARY_PALKIA_CAUGHT, LegendaryRespawn_SkipPalkia
    clearflag FLAG_LEGENDARY_PALKIA_BATTLED
LegendaryRespawn_SkipPalkia:
    goto_if_set FLAG_LEGENDARY_HEATRAN_CAUGHT, LegendaryRespawn_SkipHeatran
    clearflag FLAG_LEGENDARY_HEATRAN_BATTLED
LegendaryRespawn_SkipHeatran:
    goto_if_set FLAG_LEGENDARY_REGIGIGAS_CAUGHT, LegendaryRespawn_SkipRegigigas
    clearflag FLAG_LEGENDARY_REGIGIGAS_BATTLED
LegendaryRespawn_SkipRegigigas:
    goto_if_set FLAG_LEGENDARY_GIRATINA_CAUGHT, LegendaryRespawn_SkipGiratina
    clearflag FLAG_LEGENDARY_GIRATINA_BATTLED
LegendaryRespawn_SkipGiratina:
    goto_if_set FLAG_LEGENDARY_CRESSELIA_CAUGHT, LegendaryRespawn_SkipCresselia
    clearflag FLAG_LEGENDARY_CRESSELIA_BATTLED
LegendaryRespawn_SkipCresselia:
    goto_if_set FLAG_LEGENDARY_PHIONE_CAUGHT, LegendaryRespawn_SkipPhione
    clearflag FLAG_LEGENDARY_PHIONE_BATTLED
LegendaryRespawn_SkipPhione:
    goto_if_set FLAG_LEGENDARY_MANAPHY_CAUGHT, LegendaryRespawn_SkipManaphy
    clearflag FLAG_LEGENDARY_MANAPHY_BATTLED
LegendaryRespawn_SkipManaphy:
    goto_if_set FLAG_LEGENDARY_SHAYMIN_CAUGHT, LegendaryRespawn_SkipShaymin
    clearflag FLAG_LEGENDARY_SHAYMIN_BATTLED
LegendaryRespawn_SkipShaymin:
    goto_if_set FLAG_LEGENDARY_ARCEUS_CAUGHT, LegendaryRespawn_SkipArceus
    clearflag FLAG_LEGENDARY_ARCEUS_BATTLED
LegendaryRespawn_SkipArceus:

    @ Mythical from Step 5 list
    goto_if_set FLAG_LEGENDARY_DARKRAI_CAUGHT, LegendaryRespawn_SkipDarkrai
    clearflag FLAG_LEGENDARY_DARKRAI_BATTLED
LegendaryRespawn_SkipDarkrai:
    return

