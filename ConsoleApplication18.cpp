#include "stdafx.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include "HashMap.h"
using namespace std;

// iterator declaration
typedef HashMap<string, int>::Iterator iterDec;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// declare variables
	HashMap<string, int> hashMap;

	// Добавление элементов в таблицу
	hashMap.Insert("BIOL", 585);
	hashMap.Insert("CPSC", 386);
	hashMap.Insert("ART", 101);
	hashMap.Insert("CPSC", 462);
	hashMap.Insert("HIST", 251);
	hashMap.Insert("CPSC", 301);
	hashMap.Insert("MATH", 270);
	hashMap.Insert("PE", 145);
	hashMap.Insert("BIOL", 134);
	hashMap.Insert("GEOL", 201);
	hashMap.Insert("CIS", 465);
	hashMap.Insert("CPSC", 240);
	hashMap.Insert("GEOL", 101);
	hashMap.Insert("MATH", 150);
	hashMap.Insert("DANCE", 134);
	hashMap.Insert("CPSC", 131);
	hashMap.Insert("ART", 345);
	hashMap.Insert("CHEM", 185);
	hashMap.Insert("PE", 125);
	hashMap.Insert("CPSC", 120);

	// Количество CPSC
	cout << "Значение 'CPSC' появляется в таблице " <<
		hashMap.ContainsKey("CPSC") << " раз(а)" << endl;

	// Поиск
	iterDec it = hashMap.begin(hashMap.Hash("CPSC"));

	// Показывает 1-ое значение
	cout << "1-ый элемент со значением 'CPSC': "
		<< it[0].value << endl; 
	cout << "Все элементы со значением 'CPSC': ";
	for (int x = 0; x < hashMap.BucketSize(hashMap.Hash("CPSC")); ++x)
	{
		if (it[x].key == "CPSC") 
		{
			cout << "  Key-> " << it[x].key << "  Value-> " << it[x].value << endl;
		}
	}

	// Удаляет первый CPSC
	cout << "Удаляем элемент  с " << it[0].value << " и " << it[0].key << endl;
	hashMap.Remove("CPSC", it[0].value);

	// Количество CPSC
	cout << "Теперь значение СPSC повторяется " <<
		hashMap.ContainsKey("CPSC") << " раз(а)"<< endl;

	// Обновляем итератор до новой позиции 
	it = hashMap.begin(hashMap.Hash("CPSC"));

	// sort the values in the hash map bucket whose key is "CSPC"
	/*hashMap.Sort(hashMap.Hash("CPSC"));

	// display the values whose key matches "CPSC"
	cout << "nThese are the sorted items in the hash map whose key is 'CPSC': n";
	for (int x = 0; x < hashMap.BucketSize(hashMap.Hash("CPSC")); ++x)
	{
		if (it[x].key == "CPSC")
		{
			cout << "  Key-> " << it[x].key << "tValue-> " << it[x].value << endl;
		}
	}*/

	// Показывает все элементы в таблице
	cout << "Все элементы входящие в таблицу: "<< endl;
	for (int x = 0; x < hashMap.TableSize(); ++x)
	{
		if (!hashMap.IsEmpty(x))
		{
			for (iterDec iter = hashMap.begin(x); iter != hashMap.end(x); ++iter)
			{
				cout << "  Key-> " << (*iter).key << "  Value-> " << iter->value << endl;
			}
			cout << endl;
		}
	}

	// Количество элементов
	cout << "Количество элементов: " <<
		hashMap.TotalElems() << endl;
	getchar();
	return 0;
	getchar();
}