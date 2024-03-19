// 18.5. Понять принципы работы с памятью и научиться работать с ней при помощи указателей.

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
	// Запрос данных у пользователя с индикацией сколько еще осталось
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

	// Функция сортировки пузырьком
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

	// Функция сортировки перемешиванием. Она длиннее, но быстрее, хотя на наших объемах за скоростью ли гнаться
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

	// Создаем массив из нашей структуры
	Player* Leaderboard = new Player[NumberOfPlayers];

	for (int i = 0; i < NumberOfPlayers; ++i)
	{
		Leaderboard[i].Enter(i, NumberOfPlayers);
	}

	// Сортировка. Есть два варианта BubbleSort и ShakerSort
	Player::ShakerSort(Leaderboard, Leaderboard + NumberOfPlayers);

	for (int i = 0; i < NumberOfPlayers; ++i)
	{
		Leaderboard[i].Show();
	}

	// Очистка памяти
	delete[] Leaderboard;

	return 0;
}
