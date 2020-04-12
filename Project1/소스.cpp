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
	// �÷��̽� ����


	if () // ���ӿ��� ���� 
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
	case GAME_CONTINUE: // ��� �Ұ��
		_ptr->state = GAME_INTRO_STATE;
		break;

	case GAME_OVER: // ���� �� ���
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
		case FIRST_STATE: // STATE �ʱ� ����
			ClientPtr->state = GAME_INTRO_STATE;
			break;

		case GAME_INTRO_STATE: // ��Ʈ��
			Intro(ClientPtr);
			break;

		case GAME_PLAY_STATE: // �÷���
			GamePlay(ClientPtr);
			break;

		case GAME_OVER_STATE: // ��������
			GameOver(ClientPtr);
			break;

		case GAME_END_STATE: // �����
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