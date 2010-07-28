/* Copyright (C) 2010 by /dev/rsa for ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_RUBY_SANCTUM_H
#define DEF_RUBY_SANCTUM_H
#include "sc_boss_spell_worker.h"

enum
{
    MAX_ENCOUNTERS                 = 6,

    TYPE_EVENT                     = 0,
    TYPE_RAGEFIRE                  = 1,
    TYPE_BALTHARUS                 = 2,
    TYPE_XERESTRASZA               = 3,
    TYPE_ZARITHIAN                 = 4,
    TYPE_HALION                    = 5,

    TYPE_HALION_LOCK               = 6, //lock inside the fire ring

    TYPE_EVENT_TIMER               = 50,
    TYPE_EVENT_NPC                 = 51,

    NPC_HALION_REAL                = 39863, // Halion Physical Realm NPC
    NPC_HALION_TWILIGHT            = 40142, // Halion Twilight Realm NPC

    NPC_BALTHARUS                  = 39751,
    NPC_CLONE                      = 39899,
    NPC_ZARITHIAN                  = 39746,
    NPC_RAGEFIRE                   = 39747,

    NPC_XERESTRASZA                = 40429,

    NPC_BALTHARUS_TARGET           = 39900,
    NPC_ZARITHIAN_SPAWN_STALKER    = 39794,

    // Orb rotation
    NPC_SHADOW_PULSAR_N            = 40083, //spinning orb N spawn
    NPC_SHADOW_PULSAR_S            = 40100, //spinning orb S spawn
    NPC_ORB_CARRIER                = 40081,
    NPC_ORB_ROTATION_FOCUS         = 40091,


    GO_HALION_PORTAL_1             = 202794, //1327 ENTRY
    GO_HALION_PORTAL_2             = 202795, //1327 ENTRY
    GO_HALION_PORTAL_3             = 202796, //1327 EXIT

    GO_HALION_FIRE_WALL_S          = 203001, //9484
    GO_HALION_FIRE_WALL_L          = 203002, //9485
    GO_HALION_FIRE_WALL_M          = 203003, //9624

    GO_FIRE_FIELD                  = 203005,
    GO_FLAME_WALLS                 = 203006,
    GO_FLAME_RING                  = 203007,

    DATA_HEALTH_HALION_P           = 203,
    DATA_HEALTH_HALION_T           = 204,

    DATA_EVENT_TIMER               = 101,
    DATA_EVENT                     = 102,

    DATA_ORB_DIRECTION             = 110,
    DATA_ORB_S                     = 111,
    DATA_ORB_N                     = 112,

    //for corporeality
    DATA_P_0                       = 203,
    DATA_T_0                       = 204,
    DATA_P_1                       = 205,
    DATA_T_1                       = 206,
    DATA_P_2                       = 207,
    DATA_T_2                       = 208,
    DATA_P_BUFF                    = 209,
    DATA_T_BUFF                    = 210,

};

enum uiWorldStates
{
    UPDATE_STATE_UI_SHOW            = 5049,
    UPDATE_STATE_UI_COUNT           = 5050,
};

#endif
