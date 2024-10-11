#include <iostream>
#include <string>
#include <list>
#include <chrono>

#define R 144

using namespace std;

struct A{
	string slowo;
	string congruent_pasujacy;
	string congruent_niepasujacy;
	int kategoria;					//1=everday 2=clothing 3=nature 4=food 5=place 6=body 7=ent 8=furniture 9=animal 10=device 11=shape 12=instrument 13=vehicle 14=material 15=other		
	int rodzaj;						//meski=1, zenski=2, nijaki=3
	int used;						//0 - not used, 1 - used in 1st half, 2 - used twice	
	bool congruent;					//true - congruent, false - incongruent
};

A* utworz_Zbior() {
	A* zbiorek = new A[R];
	zbiorek[0] = { "kalendarz","olej","brama",1,1,false, 0 };
	zbiorek[1] = { "kapelusz","ziemniak","œciana",2,1,false,0 };
	zbiorek[2] = { "but","artyku³","woda",2,1,false,0 };
	zbiorek[3] = { "kwiat","zamek","stacja",3,1,false,0 };
	zbiorek[4] = { "ksiê¿yc","w³ókno","lina",3,1,false,0 };
	zbiorek[5] = { "mózg","korzeñ","kasa",6,1,false,0 };
	zbiorek[6] = { "obraz","cukier","luka",7,1,false,0 };
	zbiorek[7] = { "ogieñ","hotel","zabawa",3,1,false,0 };
	zbiorek[8] = { "stó³","film","kaczka",8,1,false,0 };
	zbiorek[9] = { "telefon","sklep","kawa",10,1,false,0 };
	zbiorek[10] = {"lew","kran","orkiestra",9,1,false,0};
	zbiorek[11] = { "cieñ","klucz","koszula",3,1,false,0 };
	zbiorek[12] = { "kolczyk","tunel","s³owo",2,1,false,0 };
	zbiorek[13] = { "rower","kamieñ","wideo",13,1,false,0 };
	zbiorek[14] = { "bêben","wieniec","ciasto",12,1,false,0 };
	zbiorek[15] = { "cmentarz","kot","b³oto",5,1,false,0 };
	zbiorek[16] = { "guzik","taniec","kino",2,1,false,0 };
	zbiorek[17] = { "jêzyk","teatr","szk³o",6,1,false,0 };
	zbiorek[18] = { "koœció³","miœ","czo³o",5,1,false,0 };
	zbiorek[19] = { "miecz","czajnik","ucho",15,1,false,0 };
	zbiorek[20] = { "tron","list","z³oto",8,1,false,0 };
	zbiorek[21] = { "ci¹gnik","fortepian","srebro",13,1,false,0 };
	zbiorek[22] = { "ser","widelec","ŸdŸb³o",4,1,false,0 };
	zbiorek[23] = { "wielb³¹d","mê¿czyzna","lotnisko",9,1,false,0 };
	zbiorek[24] = { "gazeta","brama","olej",1,2,false,0 };
	zbiorek[25] = { "góra","œciana","ziemniak",3,2,false,0 };
	zbiorek[26] = { "kostka","woda","zamek",7,2,false,0 };
	zbiorek[27] = { "lalka","stacja","w³ókno",7,2,false,0 };
	zbiorek[28] = { "mapa","luka","artyku³",1,2,false,0 };
	zbiorek[29] = { "rakieta","kasa","korzeñ",13,2,false,0 };
	zbiorek[30] = { "wró¿ka","lina","kran",15,2,false,0 };
	zbiorek[31] = { "kobieta","zabawka","hotel",15,2,false,0 };
	zbiorek[32] = { "krowa","g³owa","film",9,2,false,0 };
	zbiorek[33] = { "flaga","kaczka","cukier",1,2,false,0 };
	zbiorek[34] = { "kukurydza","orkiestra","sklep",4,2,false,0 };
	zbiorek[35] = { "œwinia","koszula","klucz",9,2,false,0 };
	zbiorek[36] = { "butelka","kawa","cia³o",1,2,false,0 };
	zbiorek[37] = { "ryba","laska","wzgórze",9,2,false,0 };
	zbiorek[38] = { "gwiazda","szafa","ramiê",3,2,false,0 };
	zbiorek[39] = { "ksi¹zka","rzeka","wino",7,2,false,0 };
	zbiorek[40] = { "wie¿a","torebka","biurko",5,2,false,0 };
	zbiorek[41] = { "sieæ","mg³a","rondo",1,2,false,0 };
	zbiorek[42] = { "bomba","szko³a","œwiat³o",15,2,false,0 };
	zbiorek[43] = { "noga","fili¿anka","wiaderko",6,2,false,0 };
	zbiorek[44] = { "rêka","herbata","jedzenie",6,2,false ,0};
	zbiorek[45] = { "noc","chata","bia³ko",3,2,false ,0};
	zbiorek[46] = { "czekolada","kuchnia","ziarno",4,2,false,0 };
	zbiorek[47] = { "fabryka","bateria","ciastko",5,2,false ,0};
	zbiorek[48] = { "¿elazko","s³owo","tunel",1,3,false ,0};
	zbiorek[49] = { "jab³ko","wideo","kamieñ",4,3,false ,0};
	zbiorek[50] = { "jezioro","kino","taniec",3,3,false ,0};
	zbiorek[51] = { "krzes³o","ciasto","wieniec",8,3,false,0 };
	zbiorek[52] = { "skrzyd³o","b³oto","kot",6,3,false,0 };
	zbiorek[53] = { "mas³o","szk³o","teatr",4,3,false,0 };
	zbiorek[54] = { "okno","czo³o","list",8,3,false,0 };
	zbiorek[55] = { "radio","ucho","czajnik",10,3,false,0 };
	zbiorek[56] = { "akwarium","z³oto","miœ",1,3,false,0 };
	zbiorek[57] = { "lustro","srebro","fortepian",1,3,false,0 };
	zbiorek[58] = { "kiwi","cia³o","widelec",4,3,false,0 };
	zbiorek[59] = { "laboratorium","ciastko","mê¿czyzna",5,3,false,0 };
	zbiorek[60] = { "serce","bia³ko","g³owa",11,3,false ,0};
	zbiorek[61] = { "miasto","wzgórze","laska",5,3,false ,0};
	zbiorek[62] = { "³ó¿ko","ramiê","rzeka",8,3,false ,0};
	zbiorek[63] = { "kolano","wino","szafa",6,3,false ,0};
	zbiorek[64] = { "jajko","wiaderko","szko³a",4,3,false ,0};
	zbiorek[65] = { "ko³o","œwiat³o","torebka",11,3,false ,0};
	zbiorek[66] = { "miêso","biurko","fili¿anka",4,3,false ,0};
	zbiorek[67] = { "oko","rondo","mg³a",6,3,false ,0};
	zbiorek[68] = { "s³oñce","jedzenie","herbata",3,3,false,0 };
	zbiorek[69] = { "myd³o","ziarno","chata",1,3,false ,0};
	zbiorek[70] = { "wiêzienie","ŸdŸb³o","bateria",5,3,false,0 };
	zbiorek[71] = { "mleko","lotnisko","kuchnia",4,3,false ,0};
	zbiorek[72] = { "kalendarz","olej","brama",1,1,false, 1 };
	zbiorek[73] = { "kapelusz","ziemniak","œciana",2,1,false,1 };
	zbiorek[74] = { "but","artyku³","woda",2,1,false,1 };
	zbiorek[75] = { "kwiat","zamek","stacja",3,1,false,1 };
	zbiorek[76] = { "ksiê¿yc","w³ókno","lina",3,1,false,1 };
	zbiorek[77] = { "mózg","korzeñ","kasa",6,1,false,1 };
	zbiorek[78] = { "obraz","cukier","luka",7,1,false,1 };
	zbiorek[79] = { "ogieñ","hotel","zabawa",3,1,false,1 };
	zbiorek[80] = { "stó³","film","kaczka",8,1,false,1 };
	zbiorek[81] = { "telefon","sklep","kawa",10,1,false,1 };
	zbiorek[82] = { "lew","kran","orkiestra",9,1,false,1 };
	zbiorek[83] = { "cieñ","klucz","koszula",3,1,false,1 };
	zbiorek[84] = { "kolczyk","tunel","s³owo",2,1,false,1 };
	zbiorek[85] = { "rower","kamieñ","wideo",13,1,false,1 };
	zbiorek[86] = { "bêben","wieniec","ciasto",12,1,false,1 };
	zbiorek[87] = { "cmentarz","kot","b³oto",5,1,false,1 };
	zbiorek[88] = { "guzik","taniec","kino",2,1,false,1 };
	zbiorek[89] = { "jêzyk","teatr","szk³o",6,1,false,1 };
	zbiorek[90] = { "koœció³","miœ","czo³o",5,1,false,1 };
	zbiorek[91] = { "miecz","czajnik","ucho",15,1,false,1 };
	zbiorek[92] = { "tron","list","z³oto",8,1,false,1 };
	zbiorek[93] = { "ci¹gnik","fortepian","srebro",13,1,false,1 };
	zbiorek[94] = { "ser","widelec","ŸdŸb³o",4,1,false,1 };
	zbiorek[95] = { "wielb³¹d","mê¿czyzna","lotnisko",9,1,false,1 };
	zbiorek[96] = { "gazeta","brama","olej",1,2,false,1 };
	zbiorek[97] = { "góra","œciana","ziemniak",3,2,false,1 };
	zbiorek[98] = { "kostka","woda","zamek",7,2,false,1 };
	zbiorek[99] = { "lalka","stacja","w³ókno",7,2,false,1 };
	zbiorek[100] = { "mapa","luka","artyku³",1,2,false,1 };
	zbiorek[101] = { "rakieta","kasa","korzeñ",13,2,false,1 };
	zbiorek[102] = { "wró¿ka","lina","kran",15,2,false,1 };
	zbiorek[103] = { "kobieta","zabawka","hotel",15,2,false,1 };
	zbiorek[104] = { "krowa","g³owa","film",9,2,false,1 };
	zbiorek[105] = { "flaga","kaczka","cukier",1,2,false,1 };
	zbiorek[106] = { "kukurydza","orkiestra","sklep",4,2,false,1 };
	zbiorek[107] = { "œwinia","koszula","klucz",9,2,false,1 };
	zbiorek[108] = { "butelka","kawa","cia³o",1,2,false,1 };
	zbiorek[109] = { "ryba","laska","wzgórze",9,2,false,1 };
	zbiorek[110] = { "gwiazda","szafa","ramiê",3,2,false,1 };
	zbiorek[111] = { "ksi¹zka","rzeka","wino",7,2,false,1 };
	zbiorek[112] = { "wie¿a","torebka","biurko",5,2,false,1 };
	zbiorek[113] = { "sieæ","mg³a","rondo",1,2,false,1 };
	zbiorek[114] = { "bomba","szko³a","œwiat³o",15,2,false,1 };
	zbiorek[115] = { "noga","fili¿anka","wiaderko",6,2,false,1 };
	zbiorek[116] = { "rêka","herbata","jedzenie",6,2,false ,1 };
	zbiorek[117] = { "noc","chata","bia³ko",3,2,false ,1 };
	zbiorek[118] = { "czekolada","kuchnia","ziarno",4,2,false,1 };
	zbiorek[119] = { "fabryka","bateria","ciastko",5,2,false ,1 };
	zbiorek[120] = { "¿elazko","s³owo","tunel",1,3,false ,1 };
	zbiorek[121] = { "jab³ko","wideo","kamieñ",4,3,false ,1 };
	zbiorek[122] = { "jezioro","kino","taniec",3,3,false ,1 };
	zbiorek[123] = { "krzes³o","ciasto","wieniec",8,3,false,1 };
	zbiorek[124] = { "skrzyd³o","b³oto","kot",6,3,false,1 };
	zbiorek[125] = { "mas³o","szk³o","teatr",4,3,false,1 };
	zbiorek[126] = { "okno","czo³o","list",8,3,false,1 };
	zbiorek[127] = { "radio","ucho","czajnik",10,3,false,1 };
	zbiorek[128] = { "akwarium","z³oto","miœ",1,3,false,1 };
	zbiorek[129] = { "lustro","srebro","fortepian",1,3,false,1 };
	zbiorek[130] = { "kiwi","cia³o","widelec",4,3,false,1 };
	zbiorek[131] = { "laboratorium","ciastko","mê¿czyzna",5,3,false,1 };
	zbiorek[132] = { "serce","bia³ko","g³owa",11,3,false ,1 };
	zbiorek[133] = { "miasto","wzgórze","laska",5,3,false ,1 };
	zbiorek[134] = { "³ó¿ko","ramiê","rzeka",8,3,false ,1 };
	zbiorek[135] = { "kolano","wino","szafa",6,3,false ,1 };
	zbiorek[136] = { "jajko","wiaderko","szko³a",4,3,false ,1 };
	zbiorek[137] = { "ko³o","œwiat³o","torebka",11,3,false ,1 };
	zbiorek[138] = { "miêso","biurko","fili¿anka",4,3,false ,1 };
	zbiorek[139] = { "oko","rondo","mg³a",6,3,false ,1 };
	zbiorek[140] = { "s³oñce","jedzenie","herbata",3,3,false,1 };
	zbiorek[141] = { "myd³o","ziarno","chata",1,3,false ,1 };
	zbiorek[142] = { "wiêzienie","ŸdŸb³o","bateria",5,3,false,1 };
	zbiorek[143] = { "mleko","lotnisko","kuchnia",4,3,false ,1 };
	return zbiorek;
}
void wypisz_zbior(A zbiorek[])
{
	for (int i = 0; i < R; i++)
	{
		if(zbiorek[i].congruent)
			cout <<i+1 << ". " << zbiorek[i].slowo << " " << zbiorek[i].congruent_pasujacy << " " << zbiorek[i].kategoria << " " << zbiorek[i].rodzaj << endl;
		else
			cout <<i+1 << ". "<< zbiorek[i].slowo << " " << zbiorek[i].congruent_niepasujacy << " " << zbiorek[i].kategoria << " " << zbiorek[i].rodzaj << endl;
	}
}


int main() {
	A* zbiorek = new A[R];
	zbiorek=utworz_Zbior();													//create the set with all the words
	bool do_lista = true;
	A* listaA = new A[R];
	while (do_lista)
	{
		unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		srand(seed);														// Reseed the random number generator
		bool losowalne = true;
		cout <<endl<< "Start the draw" << endl;
		A* lista = new A[R];
		for (int i = 0; i < R; i++)
		{
			lista[i].used = 0;
		}
		for (int i = 0; i < R; i++)
		{
			//cout<< i << endl;												//testing purposes
			if (!losowalne)													//if it's impossible to draw, break the loop and reset the list
			{
				cout << "Probably impossible to draw. Restarting" << endl;
				break;
			}
			auto start = std::chrono::high_resolution_clock::now();			//start the timer between draws
			while (lista[i].used == 0)
			{
				auto end = std::chrono::high_resolution_clock::now();
				chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(end - start);
				if (time_span.count() > 2)									//if nothing is drawn for 2 seconds, break the loop and reset the list
				{
					cout << "Draw taken too long" << endl;
					losowalne = false;
					for (int j = 0; j < R; j++)
					{
						if(lista[j].used)									//reset the used flag
							zbiorek[j].used = 0;
					}
					break;
				}
				int los = rand() % R;										//draw a random number
				if (i >= 72)
				{
					if (zbiorek[los].used==2)
						continue;
					else if (lista[i - 2].congruent && lista[i - 1].congruent && zbiorek[los].congruent)
						continue;
					else if (!lista[i - 2].congruent && !lista[i - 1].congruent && !zbiorek[los].congruent)
						continue;
					else if (lista[i - 3].kategoria == zbiorek[los].kategoria || lista[i - 2].kategoria == zbiorek[los].kategoria || lista[i - 1].kategoria == zbiorek[los].kategoria)
						continue;
					else if (lista[i - 2].rodzaj == lista[i - 1].rodzaj && lista[i - 1].rodzaj == zbiorek[los].rodzaj)
						continue;
					else if (lista[i - 2].congruent && lista[i - 2].congruent_pasujacy == zbiorek[los].congruent_niepasujacy || lista[i - 1].congruent && lista[i - 1].congruent_pasujacy == zbiorek[los].congruent_niepasujacy)
						continue;
					else if (!lista[i - 2].congruent && lista[i - 2].congruent_niepasujacy == zbiorek[los].congruent_pasujacy || !lista[i - 1].congruent && lista[i - 1].congruent_niepasujacy == zbiorek[los].congruent_pasujacy)
						continue;
					else if (lista[i - 1].slowo.at(0) == zbiorek[los].slowo.at(0))
						continue;
					else
					{
						zbiorek[los].used = 2;
						lista[i] = zbiorek[los];
					}
				}
				else if (i >= 3 && i<72)											//checking all requirements for the drawn word depending if its 1st 2nd 3rd or other word in the list
				{
					if (zbiorek[los].used)
						continue;
					else if (lista[i - 2].congruent && lista[i - 1].congruent && zbiorek[los].congruent)
						continue;
					else if (!lista[i - 2].congruent && !lista[i - 1].congruent && !zbiorek[los].congruent)
						continue;
					else if (lista[i - 3].kategoria == zbiorek[los].kategoria || lista[i - 2].kategoria == zbiorek[los].kategoria || lista[i - 1].kategoria == zbiorek[los].kategoria)
						continue;
					else if (lista[i - 2].rodzaj == lista[i - 1].rodzaj && lista[i - 1].rodzaj == zbiorek[los].rodzaj)
						continue;
					else if (lista[i - 2].congruent && lista[i - 2].congruent_pasujacy == zbiorek[los].congruent_niepasujacy || lista[i - 1].congruent && lista[i - 1].congruent_pasujacy == zbiorek[los].congruent_niepasujacy)
						continue;
					else if (!lista[i - 2].congruent && lista[i - 2].congruent_niepasujacy == zbiorek[los].congruent_pasujacy || !lista[i - 1].congruent && lista[i - 1].congruent_niepasujacy == zbiorek[los].congruent_pasujacy)
						continue;
					else if (lista[i - 1].slowo.at(0) == zbiorek[los].slowo.at(0))
						continue;
					else
					{
						if (los < 72)
						{
							zbiorek[los].used = 2;
							zbiorek[los + R / 2].used = 1;
							lista[i] = zbiorek[los];
						}
						else
						{
							zbiorek[los].used = 2;
							zbiorek[los - R / 2].used = 1;
							lista[i] = zbiorek[los];
						}
					}
				}
				else if (i == 2)
				{
					if (zbiorek[los].used)
						continue;
					else if (lista[i - 2].congruent && lista[i - 1].congruent && zbiorek[los].congruent)
						continue;
					else if (!lista[i - 2].congruent && !lista[i - 1].congruent && !zbiorek[los].congruent)
						continue;
					else if (lista[i - 2].rodzaj == lista[i - 1].rodzaj && lista[i - 1].rodzaj == zbiorek[los].rodzaj)
						continue;
					else if (lista[i - 2].congruent && lista[i - 2].congruent_pasujacy == zbiorek[los].congruent_niepasujacy || lista[i - 1].congruent && lista[i - 1].congruent_pasujacy == zbiorek[los].congruent_niepasujacy)
						continue;
					else if (!lista[i - 2].congruent && lista[i - 2].congruent_niepasujacy == zbiorek[los].congruent_pasujacy || !lista[i - 1].congruent && lista[i - 1].congruent_niepasujacy == zbiorek[los].congruent_pasujacy)
						continue;
					else if (lista[i - 1].slowo.at(0) == zbiorek[los].slowo.at(0))
						continue;
					else if (lista[i-2].kategoria == zbiorek[los].kategoria || lista[i-1].kategoria == zbiorek[los].kategoria)
						continue;
					else
					{
						if (los < 72)
						{
							zbiorek[los].used = 2;
							zbiorek[los + R / 2].used = 1;
							lista[i] = zbiorek[los];
						}
						else
						{
							zbiorek[los].used = 2;
							zbiorek[los - R / 2].used = 1;
							lista[i] = zbiorek[los];
						}
					}
				}
				else if (i == 0)
				{
					if (los < 72)
					{
						zbiorek[los].used = 2;
						zbiorek[los + R / 2].used = 1;
						lista[i] = zbiorek[los];
					}
					else
					{
						zbiorek[los].used = 2;
						zbiorek[los - R / 2].used = 1;
						lista[i] = zbiorek[los];
					}
				}
				else if (i == 1)
				{
					if (zbiorek[los].used)
						continue;
					else if (lista[i - 1].slowo.at(0) == zbiorek[los].slowo.at(0))
						continue;
					else if(lista[i-1].kategoria==zbiorek[los].kategoria)
						continue;
					else
					{
						if (los < 72)
						{
							zbiorek[los].used = 2;
							zbiorek[los + R / 2].used = 1;
							lista[i] = zbiorek[los];
						}
						else
						{
							zbiorek[los].used = 2;
							zbiorek[los - R / 2].used = 1;
							lista[i] = zbiorek[los];
						}
					}
				}
			}
		}
		if (lista[R - 1].used)										//if the last word is drawn, break the loop the list is set
		{
			do_lista = false;
			cout << "Draw finished successfully. List is set" << endl;
			for (int i = 0; i < R; i++)
			{
				listaA[i] = lista[i];
			}
			//wypisz_zbior(lista);									//testing purposes
		}
		else
		{
			for (int i = 0; i < R; i++)
			{
				if (zbiorek[i].used)									//reset the used flag
				{
					zbiorek[i].used = 0;
				}
			}
			delete[]lista;
		}
	}
	wypisz_zbior(listaA);											//print the list
	A* listaB= new A[R];
	for (int i = 0; i < R; i++)										//create the reversed the list
	{
		listaB[R-i-1] = listaA[i];
	}
	wypisz_zbior(listaB);											//print the reversed list
	return 0;
}