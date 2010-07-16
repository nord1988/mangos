/* Copyright (C) 2010 by /dev/rsa for ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_RUBY_SANCTUM_H
#define DEF_RUBY_SANCTUM_H
#include "sc_boss_spell_worker.h"

enum
{
    MAX_ENCOUNTERS                 = 5,

    TYPE_BALTHARUS                 = 0,
    TYPE_XERESTRASZA               = 1,
    TYPE_ZARITHIAN                 = 2,
    TYPE_RAGEFIRE                  = 3,
    TYPE_HALION                    = 4,

    TYPE_HALION_LOCK               = 4, //lock inside the fire ring

    NPC_HALION_P                   = 39863, // Halion Physical Realm NPC
    NPC_HALION_T                   = 40142, // Halion Twilight Realm NPC

    NPC_BALTHARUS                  = 39751,
    NPC_CLONE                      = 39899,
    NPC_ZARITHIAN                  = 39746,
    NPC_RAGEFIRE                   = 39747,

    NPC_XERESTRASZA                = 40429,

    NPC_ORB0                       = 40144,
    NPC_ORB1                       = 40145,

//    GO_HALION_FIRE_RING            = 202800, //9482
    GO_HALION_PORTAL_0             = 193988, //1327 ENTRY
    GO_HALION_PORTAL_1             = 202794, //1327 ENTRY
    GO_HALION_PORTAL_2             = 202795, //1327 EXIT
    GO_HALION_PORTAL_3             = 202797, //1327 EXIT

    GO_HALION_FIRE_RING            = 203000, //9482
    GO_HALION_FIRE_WALL_S          = 203001, //9484
    GO_HALION_FIRE_WALL_L          = 203002, //9485
    GO_HALION_FIRE_WALL_M          = 203003, //9624

    DATA_HEALTH_BALTHARUS          = 201,
    DATA_HEALTH_CLONE              = 202,
    DATA_HEALTH_HALION_P           = 203,
    DATA_HEALTH_HALION_T           = 204,

    //flame script
    DATA_RND                       = 100,
    DATA_X                         = 101,
    DATA_Y                         = 102,
    DATA_Z                         = 103,
    DATA_EVENT_TIMER               = 104,
    DATA_EVENT                     = 105,
    DATA_ORB                       = 106,

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

static Locations SpawnLoc[]=
{
    {0.0f, 0.0f, 0.0f}, // 0 HALION
    {0.0f, 0.0f, 0.0f}, // 1 PULSAR0
    {0.0f, 0.0f, 0.0f}, // 2 PULSAR1
};

#endif
