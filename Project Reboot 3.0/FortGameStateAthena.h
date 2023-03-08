#pragma once

#include "GameState.h"

enum class EAthenaGamePhase : uint8_t
{
	None = 0,
	Setup = 1,
	Warmup = 2,
	Aircraft = 3,
	SafeZones = 4,
	EndGame = 5,
	Count = 6,
	EAthenaGamePhase_MAX = 7
};

class AFortGameStateAthena : public AGameState
{
public:
	int& GetPlayersLeft()
	{
		static auto PlayersLeftOffset = GetOffset("PlayersLeft");
		return Get<int>(PlayersLeftOffset);
	}

	EAthenaGamePhase& GetGamePhase()
	{
		static auto GamePhaseOffset = GetOffset("GamePhase");
		return Get<EAthenaGamePhase>(GamePhaseOffset);
	}

	// void AddPlayerStateToGameMemberInfo(class AFortPlayerStateAthena* PlayerState);

	void OnRep_GamePhase();
	void OnRep_CurrentPlaylistInfo();
};