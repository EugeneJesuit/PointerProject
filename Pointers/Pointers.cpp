// 18.5. ������ �������� ������ � ������� � ��������� �������� � ��� ��� ������ ����������.

#include <iostream>

using namespace std;

class Player
{
private:
	string PlayerName = "Anonymous";
	int PlayerScore = 0;

public:
	Player()
	{}
	Player(string N, int S) : PlayerName(N), PlayerScore(S)
	{}

public:
	// ������ ������ � ������������ � ���������� ������� ��� ��������
	void Enter(int i, int N)
	{
		cout << "Enter name of Player " << "(" << i + 1 << "/" << N << "): ";
		cin >> PlayerName;
		cout << "Enter points: ";
		cin >> PlayerScore;
	}
	void Show()
	{
		cout << "Player Name: " << PlayerName << "\t" << "Player Score: " << PlayerScore << endl;
	}

	// ������� ���������� ���������
	void static BubbleSort(Player* Left, Player* Right)
	{
		int Size = Right - Left;
		
		if (Size <= 1)
		{
			return;
		}

		bool Condition = true;

		while (Condition)
		{
			Condition = false;

			for (Player* i = Left; i + 1 < Right; i++)
			{
				if (i->PlayerScore < (i + 1)->PlayerScore)
				{
					swap(*i, *(i + 1));
					Condition = true;
				}
			}
			Right--;
		}
	}

	// ������� ���������� ��������������. ��� �������, �� �������, ���� �� ����� ������� �� ��������� �� �������
	void static ShakerSort(Player* Left, Player* Right)
	{
		int Size = Right - Left;

		if (Size <= 1)
		{
			return;
		}

		bool Condition = true;

		Player* Begin = Left - 1;
		Player* End = Right - 1;

		while (Condition)
		{
			Condition = false;

			Begin++;

			for (Player* i = Begin; i < End; i++)
			{
				if (i->PlayerScore < (i + 1)->PlayerScore)
				{
					swap(*i, *(i + 1));
					Condition = true;
				}
			}
			if (!Condition)
			{
				break;
			}
			End--;

			for (Player* i = End; i > Begin; i--)
			{
				if (i->PlayerScore > (i - 1)->PlayerScore)
				{
					swap(*i, *(i - 1));
					Condition = true;
				}
			}
		}
	}
};

int main()
{
	int NumberOfPlayers;

	cout << "Enter number of players: ";
	cin >> NumberOfPlayers;

	// ������� ������ �� ����� ���������
	Player* Leaderboard = new Player[NumberOfPlayers];

	for (int i = 0; i < NumberOfPlayers; ++i)
	{
		Leaderboard[i].Enter(i, NumberOfPlayers);
	}

	// ����������. ���� ��� �������� BubbleSort � ShakerSort
	Player::ShakerSort(Leaderboard, Leaderboard + NumberOfPlayers);

	for (int i = 0; i < NumberOfPlayers; ++i)
	{
		Leaderboard[i].Show();
	}

	// ������� ������
	delete[] Leaderboard;

	return 0;
}
