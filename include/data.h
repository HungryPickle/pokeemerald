#ifndef GUARD_DATA_H
#define GUARD_DATA_H

#include "constants/moves.h"

#define SPECIES_SHINY_TAG 500

struct MonCoords
{
    // This would use a bitfield, but some function
    // uses it as a u8 and casting won't match.
    u8 size; // u8 width:4, height:4;
    u8 y_offset;
};

struct TrainerMonSwap
{
    u16 species;
    u16 moves[MAX_MON_MOVES];
    u8 playerLvl; // If the player has a pokemon >= this level, the mon swap triggers. A value of MON_SWAP_RANDOM, 0, or no value means this mon swap triggers at random.
};

struct TrainerMon // see include/constants/pokemon.h for all constants as of 4/23/21
{
    u16 iv; // 0-255 or USE_RANDOM_IVS
    u8 nickname[POKEMON_NAME_LENGTH + 1]; // _("Bruce")
    u8 ivs[NUM_STATS]; // BEST_IV_SPREAD_HIDDEN_POWER_BUG or {4, 20, 4, 20, 4, 20}
    u16 lvl; // value or PLAYER_LEVEL_OFFSET + value
    struct TrainerMonSwap monSwaps[MAX_MON_SWAPS]; // { {SPECIES_BUTTERFREE, {MOVE_NONE}, 10}, {SPECIES_BEEDRILL, {MOVE_PIN_MISSILE}, MON_SWAP_RANDOM} }
    u16 species; // SPECIES_MURKROW
    u16 heldItem; // ITEM_LEFTOVERS
    u16 moves[MAX_MON_MOVES]; // {MOVE_EMBER, MOVE_TACKLE, MOVE_MAGNITUDE, MOVE_SUNNY_DAY}
    u8 gender; // MON_MALE_TRAINERMON, MON_FEMALE, or value
    u8 nature; // NATURE_HARDY_TRAINERMON, NATURE_LONELY
    u8 ability; // ABILITY_SLOT_1, ABILITY_SLOT_2, ABILITY_HIDDEN
    u8 evs[NUM_STATS]; // MAX_EV_SPREAD or {4, 252, 0, 252, 0, 0}
    u8 ball; // ITEM_LUXURY_BALL
    bool32 shiny; // TRUE, FALSE
    u8 friendship; // FRIENDSHIP_FRUSTRATION, FRIENDSHIP_RETURN, or value
};

union TrainerMonPtr
{
    const struct TrainerMon *TrainerMon;
};


struct Trainer
{
    u8 partyFlags; // Unread
    u8 trainerClass;
    u8 encounterMusic_gender; // last bit is gender
    u8 trainerPic;
    u8 trainerName[12];
    u16 items[4];
    bool8 doubleBattle;
    u32 aiFlags;
    u8 partySize;
    union TrainerMonPtr party;
};

#define TRAINER_ENCOUNTER_MUSIC(trainer)((gTrainers[trainer].encounterMusic_gender & 0x7F))

extern const u16 gMinigameDigits_Pal[];
extern const u32 gMinigameDigits_Gfx[];

extern const struct SpriteFrameImage gBattlerPicTable_PlayerLeft[];
extern const struct SpriteFrameImage gBattlerPicTable_OpponentLeft[];
extern const struct SpriteFrameImage gBattlerPicTable_PlayerRight[];
extern const struct SpriteFrameImage gBattlerPicTable_OpponentRight[];
extern const struct SpriteFrameImage gTrainerBackPicTable_Brendan[];
extern const struct SpriteFrameImage gTrainerBackPicTable_May[];
extern const struct SpriteFrameImage gTrainerBackPicTable_Red[];
extern const struct SpriteFrameImage gTrainerBackPicTable_Leaf[];
extern const struct SpriteFrameImage gTrainerBackPicTable_RubySapphireBrendan[];
extern const struct SpriteFrameImage gTrainerBackPicTable_RubySapphireMay[];
extern const struct SpriteFrameImage gTrainerBackPicTable_Wally[];
extern const struct SpriteFrameImage gTrainerBackPicTable_Steven[];

extern const union AffineAnimCmd *const gAffineAnims_BattleSpritePlayerSide[];
extern const union AffineAnimCmd *const gAffineAnims_BattleSpriteOpponentSide[];
extern const union AffineAnimCmd *const gUnknown_082FF6C0[];

extern const union AnimCmd *const gUnknown_082FF70C[];
extern const struct MonCoords gMonFrontPicCoords[];
extern const struct CompressedSpriteSheet gMonStillFrontPicTable[];
extern const struct MonCoords gMonBackPicCoords[];
extern const struct CompressedSpriteSheet gMonBackPicTable[];
extern const struct CompressedSpritePalette gMonPaletteTable[];
extern const struct CompressedSpritePalette gMonShinyPaletteTable[];
extern const union AnimCmd *const *const gTrainerFrontAnimsPtrTable[];
extern const struct MonCoords gTrainerFrontPicCoords[];
extern const struct CompressedSpriteSheet gTrainerFrontPicTable[];
extern const struct CompressedSpritePalette gTrainerFrontPicPaletteTable[];
extern const union AnimCmd *const *const gTrainerBackAnimsPtrTable[];
extern const struct MonCoords gTrainerBackPicCoords[];
extern const struct CompressedSpriteSheet gTrainerBackPicTable[]; // functionally unused
extern const struct CompressedSpritePalette gTrainerBackPicPaletteTable[];

extern const u8 gEnemyMonElevation[NUM_SPECIES];

extern const union AnimCmd *const *const gMonFrontAnimsPtrTable[];
extern const struct CompressedSpriteSheet gMonFrontPicTable[];

extern const struct Trainer gTrainers[];
extern const u8 gTrainerClassNames[][13];
extern const u8 gSpeciesNames[][POKEMON_NAME_LENGTH + 1];
extern const u8 gMoveNames[MOVES_COUNT][MOVE_NAME_LENGTH + 1];

#endif // GUARD_DATA_H
