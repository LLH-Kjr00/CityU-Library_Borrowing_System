#include<iostream>
using namespace std; 
int main()
{
	char bicycle_list[8] = { '/' }, bi;
	int distance_list[8] = { 0 }, dis;
	int freq[256] = { 0 };
	bool valid = false;
	int count_valid = 0;
	int temp_bi, temp_dis;
	int count_print = 0, mini;
	while (valid == false)
	{
		cout << "Input the sharing bicycle data: ";
		for (int i = 0; i != 8; i++)
		{
			cin >> bi >> dis;
			bicycle_list[i] = bi;
			distance_list[i] = dis;
			freq[bicycle_list[i]]++;
		}
		for (int i = 0; i < 256; i++)
		{
			if (freq[i] > 1)
			{
				cout << "contains repeated bicycles!" << endl;
				for (int j = 0; j != 8; j++)
				{
					bicycle_list[j] ='/';
					distance_list[j] = 0;
				}
				for (int j = 0; j != 256; j++)
				{
					freq[j] = 0;
				}
				count_valid = 0;
			}
			if (freq[i] == 1)
			{
				count_valid++;
			}
		}
		if (count_valid == 8)
		{
			valid = true;
		}
	}
	for (int i = 0; i != 8; i++)
	{
		for (int j = 0; j != 8 - i - 1; j++)
		{
			if (distance_list[j] > distance_list[j + 1])
			{
				temp_dis = distance_list[j];
				distance_list[j] = distance_list[j + 1];
				distance_list[j + 1] = temp_dis;
				temp_bi = bicycle_list[j];
				bicycle_list[j] = bicycle_list[j + 1];
				bicycle_list[j + 1] = temp_bi;
			}
			if (distance_list[j] == distance_list[j+1])
			{
				if (bicycle_list[j] > bicycle_list[j + 1])
				{
					temp_bi = bicycle_list[j];
					bicycle_list[j] = bicycle_list[j + 1];
					bicycle_list[j + 1] = temp_bi;
				}
			}
		}
		if (distance_list[i] <= 5)
		{
			count_print++;
		}
	}
	mini = distance_list[0];
	cout << "The bicycle nearby map is: " << endl;
	if (count_print == 0)
	{
		cout << "No suitable bikes";
	}
	else
	{
		for (int j = 0; j != count_print; j++)
		{
			if (distance_list[j] == mini)
			{
				cout << bicycle_list[j] << "(" << distance_list[j] << ")* ";
			}
			else
			{
				cout << bicycle_list[j] << "(" << distance_list[j] << ") ";
			}
		}
	}
}