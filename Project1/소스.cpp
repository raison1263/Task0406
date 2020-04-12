#include <stdlib.h>
#include <stdio.h>

enum PLAYER_STATE
{
	FIRST_STATE = 1,
	GAME_INTRO_STATE,
	GAME_PLAY_STATE,
	GAME_OVER_STATE,
	GAME_END_STATE
};

enum GAME_PROCESS
{
	GAME_CONTINUE = 1,
	GAME_OVER
};

struct PLAYER
{
	PLAYER_STATE state;
};

PLAYER* AddPlayer()
{
	PLAYER* ptr = new PLAYER;
	ptr->state = FIRST_STATE;

	return ptr;
}

void ReMovePlayer(PLAYER* ptr)
{
	delete ptr;
}

void Intro(PLAYER* _ptr)
{
	_ptr->state = GAME_PLAY_STATE;
}

void GamePlay(PLAYER* _ptr)
{
	// 플레이시 내용


	if () // 게임오버 조건 
	{
		_ptr->state = GAME_OVER_STATE;
		return;
	}
}

void GameOver(PLAYER* _ptr)
{
	int result;

	switch (result)
	{
	case GAME_CONTINUE: // 계속 할경우
		_ptr->state = GAME_INTRO_STATE;
		break;

	case GAME_OVER: // 종료 할 경우
		_ptr->state = GAME_END_STATE;
		break;
	}
}

int main(int argc, char *argv[])
{
	PLAYER* ClientPtr = AddPlayer();

	while (1)
	{
		bool endflag = false;

		switch (ClientPtr->state)
		{
		case FIRST_STATE: // STATE 초기 설정
			ClientPtr->state = GAME_INTRO_STATE;
			break;

		case GAME_INTRO_STATE: // 인트로
			Intro(ClientPtr);
			break;

		case GAME_PLAY_STATE: // 플레이
			GamePlay(ClientPtr);
			break;

		case GAME_OVER_STATE: // 끝났을시
			GameOver(ClientPtr);
			break;

		case GAME_END_STATE: // 종료시
			ReMovePlayer(ClientPtr);
			endflag = true;
			break;
		}

		if (endflag)
		{
			break;
		}
	}

	return 0;
}