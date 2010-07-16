/* Copyright (C) 2006 - 2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
/* ScriptData
SDName: instance_ruby_sanctum
SD%Complete: 50%
SDComment: by notagain, corrected by /dev/rsa
SDCategory: ruby_sanctum
EndScriptData */

//TODO:  Trash mobs, spawn and removal of fire ring/walls, spawn of halion

#include "precompiled.h"
#include "def_ruby_sanctum.h"

struct MANGOS_DLL_DECL instance_ruby_sanctum : public ScriptedInstance
{
    instance_ruby_sanctum(Map* pMap) : ScriptedInstance(pMap) 
    {
        Initialize();
    }

    bool needSave;
    std::string strSaveData;

    //Creatures GUID
    uint32 m_auiEncounter[MAX_ENCOUNTERS+1];
    uint64 m_uiHalion_pGUID;
    uint64 m_uiHalion_tGUID;
    uint64 m_uiRagefireGUID;
    uint64 m_uiZarithianGUID;
    uint64 m_uiBaltharusGUID;
    uint64 m_uiCloneGUID;
    uint64 m_uiXerestraszaGUID;

    //object GUID
    uint64 m_uiHalionFireRingGUID;
    uint64 m_uiHalionPortal0GUID;
    uint64 m_uiHalionPortal1GUID;
    uint64 m_uiHalionPortal2GUID;
    uint64 m_uiHalionPortal3GUID;
    uint64 m_uiHalionFireWallSGUID;
    uint64 m_uiHalionFireWallMGUID;
    uint64 m_uiHalionFireWallLGUID;

    void OpenDoor(uint64 guid)
    {
        if(!guid)
            return;

        GameObject* pGo = instance->GetGameObject(guid);
        if(pGo)
            pGo->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
    }

    void CloseDoor(uint64 guid)
    {
        if(!guid)
            return;

        GameObject* pGo = instance->GetGameObject(guid);
        if(pGo)
            pGo->SetGoState(GO_STATE_READY);
    }

    void Initialize()
    {
        for (uint8 i = 0; i < MAX_ENCOUNTERS; ++i)
            m_auiEncounter[i] = NOT_STARTED;

        m_auiEncounter[0] = 0;

        m_uiHalion_pGUID = 0;
        m_uiHalion_tGUID = 0;
        m_uiRagefireGUID = 0;
        m_uiZarithianGUID = 0;
        m_uiBaltharusGUID = 0;
        m_uiCloneGUID = 0;
        m_uiHalionFireRingGUID = 0;
        m_uiHalionPortal0GUID = 0;
        m_uiHalionPortal1GUID = 0;
        m_uiHalionPortal2GUID = 0;
        m_uiHalionPortal3GUID = 0;
        m_uiXerestraszaGUID = 0;
        m_uiHalionFireWallSGUID = 0;
        m_uiHalionFireWallMGUID = 0;
        m_uiHalionFireWallLGUID = 0;
    }

    bool IsEncounterInProgress() const
    {
        for(uint8 i = 1; i < MAX_ENCOUNTERS-3 ; ++i)
            if (m_auiEncounter[i] == IN_PROGRESS)
                return true;

        return false;
    }

    void OnCreatureCreate(Creature* pCreature)
    {
        switch(pCreature->GetEntry())
        {
            case NPC_HALION_P: 
                m_uiHalion_pGUID = pCreature->GetGUID();
                break;
            case NPC_HALION_T: 
                m_uiHalion_tGUID = pCreature->GetGUID();
                break;
            case NPC_RAGEFIRE:
                m_uiRagefireGUID = pCreature->GetGUID();
                break;
            case NPC_ZARITHIAN:
                m_uiZarithianGUID = pCreature->GetGUID();
                break;
            case NPC_BALTHARUS:
                m_uiBaltharusGUID = pCreature->GetGUID();
                break;
            case NPC_CLONE:
                m_uiCloneGUID = pCreature->GetGUID();
                break;
            case NPC_XERESTRASZA:
                m_uiXerestraszaGUID = pCreature->GetGUID();
                break;
        }
    }

    void OnObjectCreate(GameObject* pGo)
    {
        switch(pGo->GetEntry())
        {
            case GO_HALION_FIRE_RING:
                m_uiHalionFireRingGUID = pGo->GetGUID();
                break;
            case GO_HALION_PORTAL_0:
                m_uiHalionPortal0GUID = pGo->GetGUID();
                break;
            case GO_HALION_PORTAL_1:
                m_uiHalionPortal1GUID = pGo->GetGUID();
                break;
            case GO_HALION_PORTAL_2:
                m_uiHalionPortal2GUID = pGo->GetGUID();
                break;
            case GO_HALION_PORTAL_3:
                m_uiHalionPortal3GUID = pGo->GetGUID();
                break;
        }
    }

    void SetData(uint32 uiType, uint32 uiData)
    {
        switch(uiType)
        {
            case TYPE_BALTHARUS:    m_auiEncounter[0] = uiData; break;
            case TYPE_XERESTRASZA:  m_auiEncounter[1] = uiData; break;
            case TYPE_ZARITHIAN:    m_auiEncounter[2] = uiData; break;     //SPAWN HALION?
            case TYPE_RAGEFIRE:     m_auiEncounter[3] = uiData; break;
            case TYPE_HALION:
                m_auiEncounter[4] = uiData;
                if (uiData == IN_PROGRESS)
                    CloseDoor(m_uiHalionFireRingGUID);
                else
                    OpenDoor(m_uiHalionFireRingGUID);

                if (uiData == DONE)
                    OpenDoor(m_uiHalionFireRingGUID);
                break;
        }

        if (uiData == DONE)
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;

            for(uint8 i = 0; i < MAX_ENCOUNTERS; ++i)
                saveStream << m_auiEncounter[i] << " ";

            strSaveData = saveStream.str();

            SaveToDB();
            OUT_SAVE_INST_DATA_COMPLETE;
        }
    }

    const char* Save()
    {
        return strSaveData.c_str();
    }

    uint32 GetData(uint32 uiType)
    {
        switch(uiType)
        {
            case TYPE_BALTHARUS:     return m_auiEncounter[0];
            case TYPE_XERESTRASZA:   return m_auiEncounter[1];
            case TYPE_ZARITHIAN:     return m_auiEncounter[2];
            case TYPE_RAGEFIRE:      return m_auiEncounter[3];
            case TYPE_HALION:        return m_auiEncounter[4];
        }
        return 0;
    }

    uint64 GetData64(uint32 uiData)
    {
        switch(uiData)
        {
            case NPC_BALTHARUS:  return m_uiBaltharusGUID;
            case NPC_CLONE:      return m_uiCloneGUID;
            case NPC_ZARITHIAN:  return m_uiZarithianGUID;
            case NPC_RAGEFIRE:   return m_uiRagefireGUID;
            case NPC_HALION_P:   return m_uiHalion_pGUID;
            case NPC_HALION_T:   return m_uiHalion_tGUID;
            case NPC_XERESTRASZA:               return m_uiXerestraszaGUID;
            case GO_HALION_FIRE_RING:           return m_uiHalionFireRingGUID;
            case GO_HALION_FIRE_WALL_S:         return m_uiHalionFireWallSGUID;
            case GO_HALION_FIRE_WALL_M:         return m_uiHalionFireWallMGUID;
            case GO_HALION_FIRE_WALL_L:         return m_uiHalionFireWallLGUID;
        }
        return 0;
    }

    void Load(const char* chrIn)
    {
        if (!chrIn)
        {
            OUT_LOAD_INST_DATA_FAIL;
            return;
        }

        OUT_LOAD_INST_DATA(chrIn);

        std::istringstream loadStream(chrIn);

        for(uint8 i = 0; i < MAX_ENCOUNTERS; ++i)
        {
            loadStream >> m_auiEncounter[i];

            if (m_auiEncounter[i] == IN_PROGRESS)
                m_auiEncounter[i] = NOT_STARTED;
        }

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_ruby_sanctum(Map* pMap)
{
    return new instance_ruby_sanctum(pMap);
}

void AddSC_instance_ruby_sanctum()
{
    Script* pNewScript;
    pNewScript = new Script;
    pNewScript->Name = "instance_ruby_sanctum";
    pNewScript->GetInstanceData = &GetInstanceData_instance_ruby_sanctum;
    pNewScript->RegisterSelf();
}
