static const u16 sTutorMoves[TUTOR_MOVE_COUNT] =
{
    [TUTOR_MOVE_MEGA_PUNCH] = MOVE_MEGA_PUNCH,
    [TUTOR_MOVE_SWORDS_DANCE] = MOVE_SWORDS_DANCE,
    [TUTOR_MOVE_MEGA_KICK] = MOVE_MEGA_KICK,
    [TUTOR_MOVE_BODY_SLAM] = MOVE_BODY_SLAM,
    [TUTOR_MOVE_DOUBLE_EDGE] = MOVE_DOUBLE_EDGE,
    [TUTOR_MOVE_COUNTER] = MOVE_COUNTER,
    [TUTOR_MOVE_SEISMIC_TOSS] = MOVE_SEISMIC_TOSS,
    [TUTOR_MOVE_MIMIC] = MOVE_MIMIC,
    [TUTOR_MOVE_METRONOME] = MOVE_METRONOME,
    [TUTOR_MOVE_SOFT_BOILED] = MOVE_SOFT_BOILED,
    [TUTOR_MOVE_DREAM_EATER] = MOVE_DREAM_EATER,
    [TUTOR_MOVE_THUNDER_WAVE] = MOVE_THUNDER_WAVE,
    [TUTOR_MOVE_EXPLOSION] = MOVE_EXPLOSION,
    [TUTOR_MOVE_ROCK_SLIDE] = MOVE_ROCK_SLIDE,
    [TUTOR_MOVE_SUBSTITUTE] = MOVE_SUBSTITUTE,
};

#define TUTOR(move) (1 << (TUTOR_##move))

static const u16 sTutorLearnsets[] =
{
    [SPECIES_NONE] = 0,

    [SPECIES_BULBASAUR] = TUTOR(MOVE_SWORDS_DANCE)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_IVYSAUR] = TUTOR(MOVE_SWORDS_DANCE)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_VENUSAUR] = TUTOR(MOVE_SWORDS_DANCE)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CHARMANDER] = TUTOR(MOVE_MEGA_PUNCH)
                         | TUTOR(MOVE_SWORDS_DANCE)
                         | TUTOR(MOVE_MEGA_KICK)
                         | TUTOR(MOVE_BODY_SLAM)
                         | TUTOR(MOVE_DOUBLE_EDGE)
                         | TUTOR(MOVE_COUNTER)
                         | TUTOR(MOVE_SEISMIC_TOSS)
                         | TUTOR(MOVE_MIMIC)
                         | TUTOR(MOVE_ROCK_SLIDE)
                         | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CHARMELEON] = TUTOR(MOVE_MEGA_PUNCH)
                         | TUTOR(MOVE_SWORDS_DANCE)
                         | TUTOR(MOVE_MEGA_KICK)
                         | TUTOR(MOVE_BODY_SLAM)
                         | TUTOR(MOVE_DOUBLE_EDGE)
                         | TUTOR(MOVE_COUNTER)
                         | TUTOR(MOVE_SEISMIC_TOSS)
                         | TUTOR(MOVE_MIMIC)
                         | TUTOR(MOVE_ROCK_SLIDE)
                         | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CHARIZARD] = TUTOR(MOVE_MEGA_PUNCH)
                        | TUTOR(MOVE_SWORDS_DANCE)
                        | TUTOR(MOVE_MEGA_KICK)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_SEISMIC_TOSS)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_ROCK_SLIDE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SQUIRTLE] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_WARTORTLE] = TUTOR(MOVE_MEGA_PUNCH)
                        | TUTOR(MOVE_MEGA_KICK)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_SEISMIC_TOSS)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_BLASTOISE] = TUTOR(MOVE_MEGA_PUNCH)
                        | TUTOR(MOVE_MEGA_KICK)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_SEISMIC_TOSS)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CATERPIE] = 0,

    [SPECIES_METAPOD] = 0,

    [SPECIES_BUTTERFREE] = TUTOR(MOVE_DOUBLE_EDGE)
                         | TUTOR(MOVE_MIMIC)
                         | TUTOR(MOVE_DREAM_EATER)
                         | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_WEEDLE] = 0,

    [SPECIES_KAKUNA] = 0,

    [SPECIES_BEEDRILL] = TUTOR(MOVE_SWORDS_DANCE)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_PIDGEY] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_PIDGEOTTO] = TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_PIDGEOT] = TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_RATTATA] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_RATICATE] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SPEAROW] = TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_FEAROW] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_EKANS] = TUTOR(MOVE_BODY_SLAM)
                    | TUTOR(MOVE_DOUBLE_EDGE)
                    | TUTOR(MOVE_MIMIC)
                    | TUTOR(MOVE_ROCK_SLIDE)
                    | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ARBOK] = TUTOR(MOVE_BODY_SLAM)
                    | TUTOR(MOVE_DOUBLE_EDGE)
                    | TUTOR(MOVE_MIMIC)
                    | TUTOR(MOVE_ROCK_SLIDE)
                    | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_PIKACHU] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_RAICHU] = TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_THUNDER_WAVE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SANDSHREW] = TUTOR(MOVE_SWORDS_DANCE)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_SEISMIC_TOSS)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_ROCK_SLIDE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SANDSLASH] = TUTOR(MOVE_SWORDS_DANCE)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_SEISMIC_TOSS)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_ROCK_SLIDE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_NIDORAN_F] = TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_NIDORINA] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_NIDOQUEEN] = TUTOR(MOVE_MEGA_PUNCH)
                        | TUTOR(MOVE_MEGA_KICK)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_SEISMIC_TOSS)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_ROCK_SLIDE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_NIDORAN_M] = TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_NIDORINO] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_NIDOKING] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CLEFAIRY] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_METRONOME)
                       | TUTOR(MOVE_SOFT_BOILED)
                       | TUTOR(MOVE_DREAM_EATER)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CLEFABLE] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_METRONOME)
                       | TUTOR(MOVE_SOFT_BOILED)
                       | TUTOR(MOVE_DREAM_EATER)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_VULPIX] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_NINETALES] = TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_JIGGLYPUFF] = TUTOR(MOVE_MEGA_PUNCH)
                         | TUTOR(MOVE_MEGA_KICK)
                         | TUTOR(MOVE_BODY_SLAM)
                         | TUTOR(MOVE_DOUBLE_EDGE)
                         | TUTOR(MOVE_COUNTER)
                         | TUTOR(MOVE_SEISMIC_TOSS)
                         | TUTOR(MOVE_MIMIC)
                         | TUTOR(MOVE_DREAM_EATER)
                         | TUTOR(MOVE_THUNDER_WAVE)
                         | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_WIGGLYTUFF] = TUTOR(MOVE_MEGA_PUNCH)
                         | TUTOR(MOVE_MEGA_KICK)
                         | TUTOR(MOVE_BODY_SLAM)
                         | TUTOR(MOVE_DOUBLE_EDGE)
                         | TUTOR(MOVE_COUNTER)
                         | TUTOR(MOVE_SEISMIC_TOSS)
                         | TUTOR(MOVE_MIMIC)
                         | TUTOR(MOVE_DREAM_EATER)
                         | TUTOR(MOVE_THUNDER_WAVE)
                         | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ZUBAT] = TUTOR(MOVE_DOUBLE_EDGE)
                    | TUTOR(MOVE_MIMIC)
                    | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_GOLBAT] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ODDISH] = TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_GLOOM] = TUTOR(MOVE_SWORDS_DANCE)
                    | TUTOR(MOVE_DOUBLE_EDGE)
                    | TUTOR(MOVE_MIMIC)
                    | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_VILEPLUME] = TUTOR(MOVE_SWORDS_DANCE)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_PARAS] = TUTOR(MOVE_SWORDS_DANCE)
                    | TUTOR(MOVE_BODY_SLAM)
                    | TUTOR(MOVE_DOUBLE_EDGE)
                    | TUTOR(MOVE_COUNTER)
                    | TUTOR(MOVE_MIMIC)
                    | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_PARASECT] = TUTOR(MOVE_SWORDS_DANCE)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_VENONAT] = TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_VENOMOTH] = TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_DIGLETT] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_DUGTRIO] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MEOWTH] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_PERSIAN] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_PSYDUCK] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_GOLDUCK] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MANKEY] = TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_PRIMEAPE] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_METRONOME)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_GROWLITHE] = TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ARCANINE] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_POLIWAG] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_POLIWHIRL] = TUTOR(MOVE_MEGA_PUNCH)
                        | TUTOR(MOVE_MEGA_KICK)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_SEISMIC_TOSS)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_METRONOME)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_POLIWRATH] = TUTOR(MOVE_MEGA_PUNCH)
                        | TUTOR(MOVE_MEGA_KICK)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_SEISMIC_TOSS)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_METRONOME)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ABRA] = TUTOR(MOVE_MEGA_PUNCH)
                   | TUTOR(MOVE_MEGA_KICK)
                   | TUTOR(MOVE_BODY_SLAM)
                   | TUTOR(MOVE_DOUBLE_EDGE)
                   | TUTOR(MOVE_COUNTER)
                   | TUTOR(MOVE_SEISMIC_TOSS)
                   | TUTOR(MOVE_MIMIC)
                   | TUTOR(MOVE_METRONOME)
                   | TUTOR(MOVE_DREAM_EATER)
                   | TUTOR(MOVE_THUNDER_WAVE)
                   | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_KADABRA] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_METRONOME)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ALAKAZAM] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_METRONOME)
                       | TUTOR(MOVE_DREAM_EATER)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MACHOP] = TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MACHOKE] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_METRONOME)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MACHAMP] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_METRONOME)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_BELLSPROUT] = TUTOR(MOVE_SWORDS_DANCE)
                         | TUTOR(MOVE_DOUBLE_EDGE)
                         | TUTOR(MOVE_MIMIC)
                         | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_WEEPINBELL] = TUTOR(MOVE_SWORDS_DANCE)
                         | TUTOR(MOVE_DOUBLE_EDGE)
                         | TUTOR(MOVE_MIMIC)
                         | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_VICTREEBEL] = TUTOR(MOVE_SWORDS_DANCE)
                         | TUTOR(MOVE_BODY_SLAM)
                         | TUTOR(MOVE_DOUBLE_EDGE)
                         | TUTOR(MOVE_MIMIC)
                         | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_TENTACOOL] = TUTOR(MOVE_SWORDS_DANCE)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_TENTACRUEL] = TUTOR(MOVE_SWORDS_DANCE)
                         | TUTOR(MOVE_DOUBLE_EDGE)
                         | TUTOR(MOVE_MIMIC)
                         | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_GEODUDE] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_METRONOME)
                      | TUTOR(MOVE_EXPLOSION)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_GRAVELER] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_METRONOME)
                       | TUTOR(MOVE_EXPLOSION)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_GOLEM] = TUTOR(MOVE_MEGA_PUNCH)
                    | TUTOR(MOVE_MEGA_KICK)
                    | TUTOR(MOVE_BODY_SLAM)
                    | TUTOR(MOVE_DOUBLE_EDGE)
                    | TUTOR(MOVE_COUNTER)
                    | TUTOR(MOVE_SEISMIC_TOSS)
                    | TUTOR(MOVE_MIMIC)
                    | TUTOR(MOVE_METRONOME)
                    | TUTOR(MOVE_EXPLOSION)
                    | TUTOR(MOVE_ROCK_SLIDE)
                    | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_PONYTA] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_RAPIDASH] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SLOWPOKE] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_DREAM_EATER)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SLOWBRO] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MAGNEMITE] = TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_THUNDER_WAVE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MAGNETON] = TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_FARFETCHD] = TUTOR(MOVE_SWORDS_DANCE)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_DODUO] = TUTOR(MOVE_BODY_SLAM)
                    | TUTOR(MOVE_DOUBLE_EDGE)
                    | TUTOR(MOVE_MIMIC)
                    | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_DODRIO] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SEEL] = TUTOR(MOVE_BODY_SLAM)
                   | TUTOR(MOVE_DOUBLE_EDGE)
                   | TUTOR(MOVE_MIMIC)
                   | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_DEWGONG] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_GRIMER] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MUK] = TUTOR(MOVE_BODY_SLAM)
                  | TUTOR(MOVE_MIMIC)
                  | TUTOR(MOVE_EXPLOSION)
                  | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SHELLDER] = TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_EXPLOSION)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CLOYSTER] = TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_EXPLOSION)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_GASTLY] = TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_HAUNTER] = TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_EXPLOSION)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_GENGAR] = TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ONIX] = TUTOR(MOVE_BODY_SLAM)
                   | TUTOR(MOVE_DOUBLE_EDGE)
                   | TUTOR(MOVE_MIMIC)
                   | TUTOR(MOVE_EXPLOSION)
                   | TUTOR(MOVE_ROCK_SLIDE)
                   | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_DROWZEE] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_METRONOME)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_HYPNO] = TUTOR(MOVE_MEGA_PUNCH)
                    | TUTOR(MOVE_MEGA_KICK)
                    | TUTOR(MOVE_BODY_SLAM)
                    | TUTOR(MOVE_DOUBLE_EDGE)
                    | TUTOR(MOVE_COUNTER)
                    | TUTOR(MOVE_SEISMIC_TOSS)
                    | TUTOR(MOVE_MIMIC)
                    | TUTOR(MOVE_METRONOME)
                    | TUTOR(MOVE_DREAM_EATER)
                    | TUTOR(MOVE_THUNDER_WAVE)
                    | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_KRABBY] = TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_KINGLER] = TUTOR(MOVE_SWORDS_DANCE)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_VOLTORB] = TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_EXPLOSION)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ELECTRODE] = TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_THUNDER_WAVE)
                        | TUTOR(MOVE_EXPLOSION)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_EXEGGCUTE] = TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_DREAM_EATER)
                        | TUTOR(MOVE_EXPLOSION)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_EXEGGUTOR] = TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_DREAM_EATER)
                        | TUTOR(MOVE_EXPLOSION)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CUBONE] = TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MAROWAK] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_SWORDS_DANCE)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_HITMONLEE] = TUTOR(MOVE_MEGA_PUNCH)
                        | TUTOR(MOVE_MEGA_KICK)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_SEISMIC_TOSS)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_METRONOME)
                        | TUTOR(MOVE_ROCK_SLIDE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_HITMONCHAN] = TUTOR(MOVE_MEGA_PUNCH)
                         | TUTOR(MOVE_MEGA_KICK)
                         | TUTOR(MOVE_BODY_SLAM)
                         | TUTOR(MOVE_DOUBLE_EDGE)
                         | TUTOR(MOVE_COUNTER)
                         | TUTOR(MOVE_SEISMIC_TOSS)
                         | TUTOR(MOVE_MIMIC)
                         | TUTOR(MOVE_METRONOME)
                         | TUTOR(MOVE_ROCK_SLIDE)
                         | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_LICKITUNG] = TUTOR(MOVE_MEGA_PUNCH)
                        | TUTOR(MOVE_SWORDS_DANCE)
                        | TUTOR(MOVE_MEGA_KICK)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_SEISMIC_TOSS)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_DREAM_EATER)
                        | TUTOR(MOVE_ROCK_SLIDE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_KOFFING] = TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_EXPLOSION)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_WEEZING] = TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_EXPLOSION)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_RHYHORN] = TUTOR(MOVE_SWORDS_DANCE)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_RHYDON] = TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CHANSEY] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_METRONOME)
                      | TUTOR(MOVE_SOFT_BOILED)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_TANGELA] = TUTOR(MOVE_SWORDS_DANCE)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_KANGASKHAN] = TUTOR(MOVE_MEGA_PUNCH)
                         | TUTOR(MOVE_MEGA_KICK)
                         | TUTOR(MOVE_BODY_SLAM)
                         | TUTOR(MOVE_DOUBLE_EDGE)
                         | TUTOR(MOVE_COUNTER)
                         | TUTOR(MOVE_SEISMIC_TOSS)
                         | TUTOR(MOVE_MIMIC)
                         | TUTOR(MOVE_ROCK_SLIDE)
                         | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_HORSEA] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SEADRA] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_GOLDEEN] = TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SEAKING] = TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_STARYU] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_THUNDER_WAVE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_STARMIE] = TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MR_MIME] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_METRONOME)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SCYTHER] = TUTOR(MOVE_SWORDS_DANCE)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_JYNX] = TUTOR(MOVE_MEGA_PUNCH)
                   | TUTOR(MOVE_MEGA_KICK)
                   | TUTOR(MOVE_BODY_SLAM)
                   | TUTOR(MOVE_DOUBLE_EDGE)
                   | TUTOR(MOVE_COUNTER)
                   | TUTOR(MOVE_SEISMIC_TOSS)
                   | TUTOR(MOVE_MIMIC)
                   | TUTOR(MOVE_METRONOME)
                   | TUTOR(MOVE_DREAM_EATER)
                   | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ELECTABUZZ] = TUTOR(MOVE_MEGA_PUNCH)
                         | TUTOR(MOVE_MEGA_KICK)
                         | TUTOR(MOVE_BODY_SLAM)
                         | TUTOR(MOVE_DOUBLE_EDGE)
                         | TUTOR(MOVE_COUNTER)
                         | TUTOR(MOVE_SEISMIC_TOSS)
                         | TUTOR(MOVE_MIMIC)
                         | TUTOR(MOVE_THUNDER_WAVE)
                         | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MAGMAR] = TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_PINSIR] = TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_TAUROS] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MAGIKARP] = 0,

    [SPECIES_GYARADOS] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_LAPRAS] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_DITTO] = 0,

    [SPECIES_EEVEE] = TUTOR(MOVE_BODY_SLAM)
                    | TUTOR(MOVE_DOUBLE_EDGE)
                    | TUTOR(MOVE_MIMIC)
                    | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_VAPOREON] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_JOLTEON] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_FLAREON] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_PORYGON] = TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_OMANYTE] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_OMASTAR] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_KABUTO] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_KABUTOPS] = TUTOR(MOVE_SWORDS_DANCE)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_AERODACTYL] = TUTOR(MOVE_DOUBLE_EDGE)
                         | TUTOR(MOVE_MIMIC)
                         | TUTOR(MOVE_ROCK_SLIDE)
                         | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SNORLAX] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_METRONOME)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ARTICUNO] = TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ZAPDOS] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_THUNDER_WAVE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MOLTRES] = TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_DRATINI] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_DRAGONAIR] = TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_THUNDER_WAVE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_DRAGONITE] = TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_THUNDER_WAVE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MEWTWO] = TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_THUNDER_WAVE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MEW] = TUTOR(MOVE_MEGA_PUNCH)
                  | TUTOR(MOVE_SWORDS_DANCE)
                  | TUTOR(MOVE_MEGA_KICK)
                  | TUTOR(MOVE_BODY_SLAM)
                  | TUTOR(MOVE_DOUBLE_EDGE)
                  | TUTOR(MOVE_COUNTER)
                  | TUTOR(MOVE_SEISMIC_TOSS)
                  | TUTOR(MOVE_MIMIC)
                  | TUTOR(MOVE_METRONOME)
                  | TUTOR(MOVE_SOFT_BOILED)
                  | TUTOR(MOVE_DREAM_EATER)
                  | TUTOR(MOVE_THUNDER_WAVE)
                  | TUTOR(MOVE_EXPLOSION)
                  | TUTOR(MOVE_ROCK_SLIDE)
                  | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CHIKORITA] = TUTOR(MOVE_SWORDS_DANCE)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_BAYLEEF] = TUTOR(MOVE_SWORDS_DANCE)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MEGANIUM] = TUTOR(MOVE_SWORDS_DANCE)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CYNDAQUIL] = TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_QUILAVA] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_TYPHLOSION] = TUTOR(MOVE_MEGA_PUNCH)
                         | TUTOR(MOVE_MEGA_KICK)
                         | TUTOR(MOVE_BODY_SLAM)
                         | TUTOR(MOVE_DOUBLE_EDGE)
                         | TUTOR(MOVE_COUNTER)
                         | TUTOR(MOVE_SEISMIC_TOSS)
                         | TUTOR(MOVE_MIMIC)
                         | TUTOR(MOVE_ROCK_SLIDE)
                         | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_TOTODILE] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_SWORDS_DANCE)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CROCONAW] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_SWORDS_DANCE)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_FERALIGATR] = TUTOR(MOVE_MEGA_PUNCH)
                         | TUTOR(MOVE_SWORDS_DANCE)
                         | TUTOR(MOVE_MEGA_KICK)
                         | TUTOR(MOVE_BODY_SLAM)
                         | TUTOR(MOVE_DOUBLE_EDGE)
                         | TUTOR(MOVE_COUNTER)
                         | TUTOR(MOVE_SEISMIC_TOSS)
                         | TUTOR(MOVE_MIMIC)
                         | TUTOR(MOVE_ROCK_SLIDE)
                         | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SENTRET] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_FURRET] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_HOOTHOOT] = TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_DREAM_EATER)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_NOCTOWL] = TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_LEDYBA] = TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_LEDIAN] = TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SPINARAK] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ARIADOS] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CROBAT] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CHINCHOU] = TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_LANTURN] = TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_PICHU] = TUTOR(MOVE_MEGA_PUNCH)
                    | TUTOR(MOVE_MEGA_KICK)
                    | TUTOR(MOVE_BODY_SLAM)
                    | TUTOR(MOVE_DOUBLE_EDGE)
                    | TUTOR(MOVE_COUNTER)
                    | TUTOR(MOVE_SEISMIC_TOSS)
                    | TUTOR(MOVE_MIMIC)
                    | TUTOR(MOVE_THUNDER_WAVE)
                    | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CLEFFA] = TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_SOFT_BOILED)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_THUNDER_WAVE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_IGGLYBUFF] = TUTOR(MOVE_MEGA_PUNCH)
                        | TUTOR(MOVE_MEGA_KICK)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_SEISMIC_TOSS)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_DREAM_EATER)
                        | TUTOR(MOVE_THUNDER_WAVE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_TOGEPI] = TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_SOFT_BOILED)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_THUNDER_WAVE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_TOGETIC] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_METRONOME)
                      | TUTOR(MOVE_SOFT_BOILED)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_NATU] = TUTOR(MOVE_DOUBLE_EDGE)
                   | TUTOR(MOVE_MIMIC)
                   | TUTOR(MOVE_DREAM_EATER)
                   | TUTOR(MOVE_THUNDER_WAVE)
                   | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_XATU] = TUTOR(MOVE_DOUBLE_EDGE)
                   | TUTOR(MOVE_MIMIC)
                   | TUTOR(MOVE_DREAM_EATER)
                   | TUTOR(MOVE_THUNDER_WAVE)
                   | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MAREEP] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_THUNDER_WAVE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_FLAAFFY] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_AMPHAROS] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_BELLOSSOM] = TUTOR(MOVE_SWORDS_DANCE)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MARILL] = TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_AZUMARILL] = TUTOR(MOVE_MEGA_PUNCH)
                        | TUTOR(MOVE_MEGA_KICK)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_SEISMIC_TOSS)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SUDOWOODO] = TUTOR(MOVE_MEGA_PUNCH)
                        | TUTOR(MOVE_MEGA_KICK)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_SEISMIC_TOSS)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_EXPLOSION)
                        | TUTOR(MOVE_ROCK_SLIDE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_POLITOED] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_METRONOME)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_HOPPIP] = TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SKIPLOOM] = TUTOR(MOVE_SWORDS_DANCE)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_JUMPLUFF] = TUTOR(MOVE_SWORDS_DANCE)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_AIPOM] = TUTOR(MOVE_MEGA_PUNCH)
                    | TUTOR(MOVE_MEGA_KICK)
                    | TUTOR(MOVE_BODY_SLAM)
                    | TUTOR(MOVE_DOUBLE_EDGE)
                    | TUTOR(MOVE_COUNTER)
                    | TUTOR(MOVE_SEISMIC_TOSS)
                    | TUTOR(MOVE_MIMIC)
                    | TUTOR(MOVE_METRONOME)
                    | TUTOR(MOVE_DREAM_EATER)
                    | TUTOR(MOVE_THUNDER_WAVE)
                    | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SUNKERN] = TUTOR(MOVE_SWORDS_DANCE)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SUNFLORA] = TUTOR(MOVE_SWORDS_DANCE)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_YANMA] = TUTOR(MOVE_DOUBLE_EDGE)
                    | TUTOR(MOVE_MIMIC)
                    | TUTOR(MOVE_DREAM_EATER)
                    | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_WOOPER] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_QUAGSIRE] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ESPEON] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_UMBREON] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MURKROW] = TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SLOWKING] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_DREAM_EATER)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MISDREAVUS] = TUTOR(MOVE_DOUBLE_EDGE)
                         | TUTOR(MOVE_MIMIC)
                         | TUTOR(MOVE_DREAM_EATER)
                         | TUTOR(MOVE_THUNDER_WAVE)
                         | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_UNOWN] = 0,

    [SPECIES_WOBBUFFET] = 0,

    [SPECIES_GIRAFARIG] = TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_DREAM_EATER)
                        | TUTOR(MOVE_THUNDER_WAVE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_PINECO] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_FORRETRESS] = TUTOR(MOVE_BODY_SLAM)
                         | TUTOR(MOVE_DOUBLE_EDGE)
                         | TUTOR(MOVE_COUNTER)
                         | TUTOR(MOVE_MIMIC)
                         | TUTOR(MOVE_EXPLOSION)
                         | TUTOR(MOVE_ROCK_SLIDE)
                         | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_DUNSPARCE] = TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_DREAM_EATER)
                        | TUTOR(MOVE_THUNDER_WAVE)
                        | TUTOR(MOVE_ROCK_SLIDE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_GLIGAR] = TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_STEELIX] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_EXPLOSION)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SNUBBULL] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_METRONOME)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_GRANBULL] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_METRONOME)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_QWILFISH] = TUTOR(MOVE_SWORDS_DANCE)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SCIZOR] = TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SHUCKLE] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_HERACROSS] = TUTOR(MOVE_SWORDS_DANCE)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_SEISMIC_TOSS)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_ROCK_SLIDE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SNEASEL] = TUTOR(MOVE_SWORDS_DANCE)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_TEDDIURSA] = TUTOR(MOVE_MEGA_PUNCH)
                        | TUTOR(MOVE_SWORDS_DANCE)
                        | TUTOR(MOVE_MEGA_KICK)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_SEISMIC_TOSS)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_METRONOME)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_URSARING] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_SWORDS_DANCE)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_METRONOME)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SLUGMA] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MAGCARGO] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SWINUB] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_PILOSWINE] = TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_ROCK_SLIDE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CORSOLA] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_EXPLOSION)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_REMORAID] = TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_OCTILLERY] = TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_SEISMIC_TOSS)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_THUNDER_WAVE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_DELIBIRD] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MANTINE] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SKARMORY] = TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_HOUNDOUR] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_DREAM_EATER)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_HOUNDOOM] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_DREAM_EATER)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_KINGDRA] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_PHANPY] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_DONPHAN] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_PORYGON2] = TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_DREAM_EATER)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_STANTLER] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_DREAM_EATER)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SMEARGLE] = 0,

    [SPECIES_TYROGUE] = TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_HITMONTOP] = TUTOR(MOVE_MEGA_KICK)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_SEISMIC_TOSS)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_ROCK_SLIDE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SMOOCHUM] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_METRONOME)
                       | TUTOR(MOVE_DREAM_EATER)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ELEKID] = TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_THUNDER_WAVE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MAGBY] = TUTOR(MOVE_MEGA_PUNCH)
                    | TUTOR(MOVE_MEGA_KICK)
                    | TUTOR(MOVE_BODY_SLAM)
                    | TUTOR(MOVE_DOUBLE_EDGE)
                    | TUTOR(MOVE_COUNTER)
                    | TUTOR(MOVE_SEISMIC_TOSS)
                    | TUTOR(MOVE_MIMIC)
                    | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MILTANK] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_METRONOME)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_BLISSEY] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_METRONOME)
                      | TUTOR(MOVE_SOFT_BOILED)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_RAIKOU] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_THUNDER_WAVE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ENTEI] = TUTOR(MOVE_BODY_SLAM)
                    | TUTOR(MOVE_DOUBLE_EDGE)
                    | TUTOR(MOVE_MIMIC)
                    | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SUICUNE] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_LARVITAR] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_PUPITAR] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_TYRANITAR] = TUTOR(MOVE_MEGA_PUNCH)
                        | TUTOR(MOVE_MEGA_KICK)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_SEISMIC_TOSS)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_THUNDER_WAVE)
                        | TUTOR(MOVE_ROCK_SLIDE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_LUGIA] = TUTOR(MOVE_BODY_SLAM)
                    | TUTOR(MOVE_DOUBLE_EDGE)
                    | TUTOR(MOVE_MIMIC)
                    | TUTOR(MOVE_DREAM_EATER)
                    | TUTOR(MOVE_THUNDER_WAVE)
                    | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_HO_OH] = TUTOR(MOVE_DOUBLE_EDGE)
                    | TUTOR(MOVE_MIMIC)
                    | TUTOR(MOVE_DREAM_EATER)
                    | TUTOR(MOVE_THUNDER_WAVE)
                    | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CELEBI] = TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_TREECKO] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_SWORDS_DANCE)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_GROVYLE] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_SWORDS_DANCE)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SCEPTILE] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_SWORDS_DANCE)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_TORCHIC] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_SWORDS_DANCE)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_COMBUSKEN] = TUTOR(MOVE_MEGA_PUNCH)
                        | TUTOR(MOVE_SWORDS_DANCE)
                        | TUTOR(MOVE_MEGA_KICK)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_SEISMIC_TOSS)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_ROCK_SLIDE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_BLAZIKEN] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_SWORDS_DANCE)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MUDKIP] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MARSHTOMP] = TUTOR(MOVE_MEGA_PUNCH)
                        | TUTOR(MOVE_MEGA_KICK)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_SEISMIC_TOSS)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_ROCK_SLIDE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SWAMPERT] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_POOCHYENA] = TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MIGHTYENA] = TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ZIGZAGOON] = TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_THUNDER_WAVE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_LINOONE] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_WURMPLE] = 0,

    [SPECIES_SILCOON] = 0,

    [SPECIES_BEAUTIFLY] = TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CASCOON] = 0,

    [SPECIES_DUSTOX] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_LOTAD] = TUTOR(MOVE_SWORDS_DANCE)
                    | TUTOR(MOVE_BODY_SLAM)
                    | TUTOR(MOVE_DOUBLE_EDGE)
                    | TUTOR(MOVE_MIMIC)
                    | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_LOMBRE] = TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_LUDICOLO] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_SWORDS_DANCE)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_METRONOME)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SEEDOT] = TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_NUZLEAF] = TUTOR(MOVE_SWORDS_DANCE)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_EXPLOSION)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SHIFTRY] = TUTOR(MOVE_SWORDS_DANCE)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_EXPLOSION)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_NINCADA] = TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_NINJASK] = TUTOR(MOVE_SWORDS_DANCE)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SHEDINJA] = TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_DREAM_EATER)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_TAILLOW] = TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SWELLOW] = TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SHROOMISH] = TUTOR(MOVE_SWORDS_DANCE)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_BRELOOM] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_SWORDS_DANCE)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SPINDA] = TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_WINGULL] = TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_PELIPPER] = TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SURSKIT] = TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MASQUERAIN] = TUTOR(MOVE_DOUBLE_EDGE)
                         | TUTOR(MOVE_MIMIC)
                         | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_WAILMER] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_WAILORD] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SKITTY] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_THUNDER_WAVE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_DELCATTY] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_DREAM_EATER)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_KECLEON] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_METRONOME)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_BALTOY] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CLAYDOL] = TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_EXPLOSION)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_NOSEPASS] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_EXPLOSION)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_TORKOAL] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_EXPLOSION)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SABLEYE] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_METRONOME)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_BARBOACH] = TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_WHISCASH] = TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_LUVDISC] = TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CORPHISH] = TUTOR(MOVE_SWORDS_DANCE)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CRAWDAUNT] = TUTOR(MOVE_SWORDS_DANCE)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_FEEBAS] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MILOTIC] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CARVANHA] = TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SHARPEDO] = TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_TRAPINCH] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_VIBRAVA] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_FLYGON] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MAKUHITA] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_METRONOME)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_HARIYAMA] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_METRONOME)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ELECTRIKE] = TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_THUNDER_WAVE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MANECTRIC] = TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_THUNDER_WAVE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_NUMEL] = TUTOR(MOVE_BODY_SLAM)
                    | TUTOR(MOVE_DOUBLE_EDGE)
                    | TUTOR(MOVE_MIMIC)
                    | TUTOR(MOVE_ROCK_SLIDE)
                    | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CAMERUPT] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_EXPLOSION)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SPHEAL] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SEALEO] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_WALREIN] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CACNEA] = TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CACTURNE] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_SWORDS_DANCE)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SNORUNT] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_GLALIE] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_LUNATONE] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_DREAM_EATER)
                       | TUTOR(MOVE_EXPLOSION)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SOLROCK] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_EXPLOSION)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_AZURILL] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SPOINK] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_GRUMPIG] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_PLUSLE] = TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_THUNDER_WAVE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MINUN] = TUTOR(MOVE_MEGA_PUNCH)
                    | TUTOR(MOVE_MEGA_KICK)
                    | TUTOR(MOVE_BODY_SLAM)
                    | TUTOR(MOVE_DOUBLE_EDGE)
                    | TUTOR(MOVE_COUNTER)
                    | TUTOR(MOVE_SEISMIC_TOSS)
                    | TUTOR(MOVE_MIMIC)
                    | TUTOR(MOVE_METRONOME)
                    | TUTOR(MOVE_THUNDER_WAVE)
                    | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MAWILE] = TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MEDITITE] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_METRONOME)
                       | TUTOR(MOVE_DREAM_EATER)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MEDICHAM] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_METRONOME)
                       | TUTOR(MOVE_DREAM_EATER)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SWABLU] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ALTARIA] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_WYNAUT] = 0,

    [SPECIES_DUSKULL] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_DUSCLOPS] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_METRONOME)
                       | TUTOR(MOVE_DREAM_EATER)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ROSELIA] = TUTOR(MOVE_SWORDS_DANCE)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SLAKOTH] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_VIGOROTH] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SLAKING] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_GULPIN] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SWALOT] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_TROPIUS] = TUTOR(MOVE_SWORDS_DANCE)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_WHISMUR] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_LOUDRED] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_EXPLOUD] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CLAMPERL] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_HUNTAIL] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_GOREBYSS] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ABSOL] = TUTOR(MOVE_SWORDS_DANCE)
                    | TUTOR(MOVE_BODY_SLAM)
                    | TUTOR(MOVE_DOUBLE_EDGE)
                    | TUTOR(MOVE_COUNTER)
                    | TUTOR(MOVE_MIMIC)
                    | TUTOR(MOVE_DREAM_EATER)
                    | TUTOR(MOVE_THUNDER_WAVE)
                    | TUTOR(MOVE_ROCK_SLIDE)
                    | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SHUPPET] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_BANETTE] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_METRONOME)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SEVIPER] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ZANGOOSE] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_SWORDS_DANCE)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_RELICANTH] = TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_ROCK_SLIDE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ARON] = TUTOR(MOVE_BODY_SLAM)
                   | TUTOR(MOVE_DOUBLE_EDGE)
                   | TUTOR(MOVE_MIMIC)
                   | TUTOR(MOVE_ROCK_SLIDE)
                   | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_LAIRON] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_AGGRON] = TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_THUNDER_WAVE)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CASTFORM] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_VOLBEAT] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_METRONOME)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ILLUMISE] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_METRONOME)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_LILEEP] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CRADILY] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ANORITH] = TUTOR(MOVE_SWORDS_DANCE)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ARMALDO] = TUTOR(MOVE_SWORDS_DANCE)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_RALTS] = TUTOR(MOVE_BODY_SLAM)
                    | TUTOR(MOVE_DOUBLE_EDGE)
                    | TUTOR(MOVE_MIMIC)
                    | TUTOR(MOVE_DREAM_EATER)
                    | TUTOR(MOVE_THUNDER_WAVE)
                    | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_KIRLIA] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_THUNDER_WAVE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_GARDEVOIR] = TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_DREAM_EATER)
                        | TUTOR(MOVE_THUNDER_WAVE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_BAGON] = TUTOR(MOVE_BODY_SLAM)
                    | TUTOR(MOVE_DOUBLE_EDGE)
                    | TUTOR(MOVE_MIMIC)
                    | TUTOR(MOVE_ROCK_SLIDE)
                    | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SHELGON] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SALAMENCE] = TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_ROCK_SLIDE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_BELDUM] = 0,

    [SPECIES_METANG] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_METAGROSS] = TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_EXPLOSION)
                        | TUTOR(MOVE_ROCK_SLIDE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_REGIROCK] = TUTOR(MOVE_MEGA_PUNCH)
                       | TUTOR(MOVE_MEGA_KICK)
                       | TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_COUNTER)
                       | TUTOR(MOVE_SEISMIC_TOSS)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_EXPLOSION)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_REGICE] = TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_THUNDER_WAVE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_REGISTEEL] = TUTOR(MOVE_MEGA_PUNCH)
                        | TUTOR(MOVE_MEGA_KICK)
                        | TUTOR(MOVE_BODY_SLAM)
                        | TUTOR(MOVE_DOUBLE_EDGE)
                        | TUTOR(MOVE_COUNTER)
                        | TUTOR(MOVE_SEISMIC_TOSS)
                        | TUTOR(MOVE_MIMIC)
                        | TUTOR(MOVE_THUNDER_WAVE)
                        | TUTOR(MOVE_EXPLOSION)
                        | TUTOR(MOVE_ROCK_SLIDE)
                        | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_KYOGRE] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_THUNDER_WAVE)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_GROUDON] = TUTOR(MOVE_MEGA_PUNCH)
                      | TUTOR(MOVE_SWORDS_DANCE)
                      | TUTOR(MOVE_MEGA_KICK)
                      | TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_COUNTER)
                      | TUTOR(MOVE_SEISMIC_TOSS)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_ROCK_SLIDE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_RAYQUAZA] = TUTOR(MOVE_BODY_SLAM)
                       | TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_THUNDER_WAVE)
                       | TUTOR(MOVE_ROCK_SLIDE)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_LATIAS] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_THUNDER_WAVE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_LATIOS] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_THUNDER_WAVE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_JIRACHI] = TUTOR(MOVE_BODY_SLAM)
                      | TUTOR(MOVE_DOUBLE_EDGE)
                      | TUTOR(MOVE_MIMIC)
                      | TUTOR(MOVE_METRONOME)
                      | TUTOR(MOVE_DREAM_EATER)
                      | TUTOR(MOVE_THUNDER_WAVE)
                      | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_DEOXYS] = TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_THUNDER_WAVE)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CHIMECHO] = TUTOR(MOVE_DOUBLE_EDGE)
                       | TUTOR(MOVE_MIMIC)
                       | TUTOR(MOVE_DREAM_EATER)
                       | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_LUXIO] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_LUXRAY] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_FRAXURE] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_HAXORUS] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_DOUBLADE] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_AEGISLASH] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_GALARIAN_LINOONE] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_OBSTAGOON] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_STARLY] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_STARAVIA] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_STARAPTOR] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_MUNCHLAX] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_PORYGON_Z] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_HISUIAN_ZORUA] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_HISUIAN_ZOROARK] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_FLETCHLING] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_FLETCHINDER] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_TALONFLAME] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_URSALUNA] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_SALANDIT] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SALAZZLE] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_LITWICK] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_LAMPENT] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_CHANDELURE] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_CHIMCHAR] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MONFERNO] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_INFERNAPE] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_PIPLUP] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_PRINPLUP] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_EMPOLEON] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_BUIZEL] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_FLOATZEL] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MAGMORTAR] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ELECTIVIRE] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_ROTOM] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_ROTOM_HEAT] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_ROTOM_WASH] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_ROTOM_FROST] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_ROTOM_FAN] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_ROTOM_MOW] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_TOXEL] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_TOXTRICITY] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_TYNAMO] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_EELEKTRIK] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_EELEKTROSS] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_ROSERADE] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_TANGROWTH] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_LEAFEON] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_GLACEON] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_SYLVEON] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_FERROSEED] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_FERROTHORN] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_PUMPKABOO] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_GOURGEIST] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_PHANTUMP] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_TREVENANT] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_GALARIAN_MR_MIME] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_MR_RIME] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_MAMOSWINE] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_FROSLASS] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_WEAVILE] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_GALARIAN_DARUMAKA] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_GALARIAN_DARMANITAN] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_ANNIHILAPE] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_GALARIAN_FARFETCHD] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_SIRFETCHD] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_PANCHAM] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_PANGORO] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_CROAGUNK] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_TOXICROAK] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_RIOLU] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_LUCARIO] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_SCRAGGY] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_SCRAFTY] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_SKRELP] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_DRAGALGE] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_GIBLE] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_GABITE] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_GARCHOMP] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_GLISCOR] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_RHYPERIOR] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_DRILBUR] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_EXCADRILL] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_SANDILE] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_KROKOROK] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_KROOKODILE] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_GOLETT] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_GOLURK] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_HONCHKROW] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_TOGEKISS] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_YANMEGA] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_HAWLUCHA] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_ROOKIDEE] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CORVISQUIRE] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_CORVIKNIGHT] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_GALLADE] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_INKAY] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_MALAMAR] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_LARVESTA] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_VOLCARONA] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_GRUBBIN] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_CHARJABUG] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_VIKAVOLT] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_SIZZLIPEDE] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_CENTISKORCH] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_KLEAVOR] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_HISUIAN_GROWLITHE] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_HISUIAN_ARCANINE] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_ALOLAN_GEODUDE] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_ALOLAN_GRAVELER] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_ALOLAN_GOLEM] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_PROBOPASS] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_ROCKRUFF] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_LYCANROC] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_DREEPY] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_DRAKLOAK] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_DRAGAPULT] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_BASCULIN] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_BASCULEGION] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_ALOLAN_EXEGGUTOR] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_DEINO] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_ZWEILOUS] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_HYDREIGON] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_GOOMY] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_SLIGGOO] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_GOODRA] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_DARKRAI] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_ZORUA] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_ZOROARK] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_PAWNIARD] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_BISHARP] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_KINGAMBIT] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_BRONZOR] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_BRONZONG] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_GALARIAN_MEOWTH] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_PERRSERKER] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_ALOLAN_MEOWTH] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_ALOLAN_PERSIAN] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_DURALUDON] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_ARCHALUDON] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_TINKATINK] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_TINKATUFF] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_TINKATON] = TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_ALOLAN_DIGLETT] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_ALOLAN_DUGTRIO] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_MAGNEZONE] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_FLABEBE] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_FLOETTE] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_FLORGES] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_ALOLAN_VULPIX] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_ALOLAN_NINETALES] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_UXIE] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_MESPRIT] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_AZELF] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_DIALGA] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_PALKIA] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_HEATRAN] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_REGIGIGAS] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_GIRATINA] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_ROCK_SLIDE)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_CRESSELIA] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_DREAM_EATER)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

    [SPECIES_PHIONE] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_MANAPHY] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE),

    [SPECIES_SHAYMIN] = TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_SWORDS_DANCE),

    [SPECIES_ARCEUS] = TUTOR(MOVE_BODY_SLAM)
                     | TUTOR(MOVE_COUNTER)
                     | TUTOR(MOVE_DOUBLE_EDGE)
                     | TUTOR(MOVE_EXPLOSION)
                     | TUTOR(MOVE_MEGA_KICK)
                     | TUTOR(MOVE_MEGA_PUNCH)
                     | TUTOR(MOVE_METRONOME)
                     | TUTOR(MOVE_MIMIC)
                     | TUTOR(MOVE_SEISMIC_TOSS)
                     | TUTOR(MOVE_SUBSTITUTE)
                     | TUTOR(MOVE_THUNDER_WAVE),

};
