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
	int rodzaj_cong;				//cong pasujacy=0, meski=1, zenski=2, nijaki=3
};

A* utworz_Zbior() {
	A* zbiorek = new A[R];
	zbiorek[0] = { "kalendarz","olej","brama",1,1,false, 0,2 };
	zbiorek[1] = { "kapelusz","ziemniak","œciana",2,1,false,0,2 };
	zbiorek[2] = { "but","artyku³","woda",2,1,false,0,2 };
	zbiorek[3] = { "kwiat","zamek","stacja",3,1,false,0,2 };
	zbiorek[4] = { "ksiê¿yc","w³ókno","lina",3,1,false,0,2 };
	zbiorek[5] = { "mózg","korzeñ","kasa",6,1,false,0,2 };
	zbiorek[6] = { "obraz","cukier","luka",7,1,false,0,2 };
	zbiorek[7] = { "ogieñ","hotel","zabawa",3,1,false,0,2 };
	zbiorek[8] = { "stó³","film","kaczka",8,1,false,0,2 };
	zbiorek[9] = { "telefon","sklep","kawa",10,1,false,0,2 };
	zbiorek[10] = {"lew","kran","orkiestra",9,1,false,0,2};
	zbiorek[11] = { "cieñ","klucz","koszula",3,1,false,0,2 };
	zbiorek[12] = { "kolczyk","tunel","s³owo",2,1,false,0,3 };
	zbiorek[13] = { "rower","kamieñ","wideo",13,1,false,0 ,3};
	zbiorek[14] = { "bêben","wieniec","ciasto",12,1,false,0 ,3};
	zbiorek[15] = { "cmentarz","kot","b³oto",5,1,false,0,3 };
	zbiorek[16] = { "guzik","taniec","kino",2,1,false,0,3 };
	zbiorek[17] = { "jêzyk","teatr","szk³o",6,1,false,0,3 };
	zbiorek[18] = { "koœció³","miœ","czo³o",5,1,false,0,3 };
	zbiorek[19] = { "miecz","czajnik","ucho",15,1,false,0,3 };
	zbiorek[20] = { "tron","list","z³oto",8,1,false,0,3 };
	zbiorek[21] = { "ci¹gnik","fortepian","srebro",13,1,false,0,3 };
	zbiorek[22] = { "ser","widelec","ŸdŸb³o",4,1,false,0,3 };
	zbiorek[23] = { "wielb³¹d","mê¿czyzna","lotnisko",9,1,false,0,3 };
	zbiorek[24] = { "gazeta","brama","olej",1,2,false,0,1 };
	zbiorek[25] = { "góra","œciana","ziemniak",3,2,false,0,1 };
	zbiorek[26] = { "kostka","woda","zamek",7,2,false,0,1 };
	zbiorek[27] = { "lalka","stacja","w³ókno",7,2,false,0,1 };
	zbiorek[28] = { "mapa","luka","artyku³",1,2,false,0,1 };
	zbiorek[29] = { "rakieta","kasa","korzeñ",13,2,false,0,1 };
	zbiorek[30] = { "wró¿ka","lina","kran",15,2,false,0,1 };
	zbiorek[31] = { "kobieta","zabawka","hotel",15,2,false,0,1 };
	zbiorek[32] = { "krowa","g³owa","film",9,2,false,0,1 };
	zbiorek[33] = { "flaga","kaczka","cukier",1,2,false,0,1 };
	zbiorek[34] = { "kukurydza","orkiestra","sklep",4,2,false,0,1 };
	zbiorek[35] = { "œwinia","koszula","klucz",9,2,false,0,1 };
	zbiorek[36] = { "butelka","kawa","cia³o",1,2,false,0,3 };
	zbiorek[37] = { "ryba","laska","wzgórze",9,2,false,0,3 };
	zbiorek[38] = { "gwiazda","szafa","ramiê",3,2,false,0,3 };
	zbiorek[39] = { "ksi¹¿ka","rzeka","wino",7,2,false,0,3 };
	zbiorek[40] = { "wie¿a","torebka","biurko",5,2,false,0,3 };
	zbiorek[41] = { "sieæ","mg³a","rondo",1,2,false,0,3 };
	zbiorek[42] = { "bomba","szko³a","œwiat³o",15,2,false,0,3 };
	zbiorek[43] = { "noga","fili¿anka","wiaderko",6,2,false,0,3 };
	zbiorek[44] = { "rêka","herbata","jedzenie",6,2,false ,0,3};
	zbiorek[45] = { "noc","chata","bia³ko",3,2,false ,0,3};
	zbiorek[46] = { "czekolada","kuchnia","ziarno",4,2,false,0,3 };
	zbiorek[47] = { "fabryka","bateria","ciastko",5,2,false ,0,3};
	zbiorek[48] = { "¿elazko","s³owo","tunel",1,3,false ,0,1};
	zbiorek[49] = { "jab³ko","wideo","kamieñ",4,3,false ,0,1};
	zbiorek[50] = { "jezioro","kino","taniec",3,3,false ,0,1};
	zbiorek[51] = { "krzes³o","ciasto","wieniec",8,3,false,0,1 };
	zbiorek[52] = { "skrzyd³o","b³oto","kot",6,3,false,0,1 };
	zbiorek[53] = { "mas³o","szk³o","teatr",4,3,false,0,1 };
	zbiorek[54] = { "okno","czo³o","list",8,3,false,0,1 };
	zbiorek[55] = { "radio","ucho","czajnik",10,3,false,0,1 };
	zbiorek[56] = { "akwarium","z³oto","miœ",1,3,false,0,1 };
	zbiorek[57] = { "lustro","srebro","fortepian",1,3,false,0,1 };
	zbiorek[58] = { "kiwi","cia³o","widelec",4,3,false,0,1 };
	zbiorek[59] = { "laboratorium","ciastko","mê¿czyzna",5,3,false,0,1 };
	zbiorek[60] = { "serce","bia³ko","g³owa",11,3,false ,0,2};
	zbiorek[61] = { "miasto","wzgórze","laska",5,3,false ,0,2};
	zbiorek[62] = { "³ó¿ko","ramiê","rzeka",8,3,false ,0,2};
	zbiorek[63] = { "kolano","wino","szafa",6,3,false ,0,2};
	zbiorek[64] = { "jajko","wiaderko","szko³a",4,3,false ,0,2};
	zbiorek[65] = { "ko³o","œwiat³o","torebka",11,3,false ,0,2};
	zbiorek[66] = { "miêso","biurko","fili¿anka",4,3,false ,0,2};
	zbiorek[67] = { "oko","rondo","mg³a",6,3,false ,0,2};
	zbiorek[68] = { "s³oñce","jedzenie","herbata",3,3,false,0,2 };
	zbiorek[69] = { "myd³o","ziarno","chata",1,3,false ,0,2};
	zbiorek[70] = { "wiêzienie","ŸdŸb³o","bateria",5,3,false,0,2 };
	zbiorek[71] = { "mleko","lotnisko","kuchnia",4,3,false ,0,2};
	zbiorek[72] = { "kalendarz","olej","brama",1,1,false, 1,0 };
	zbiorek[73] = { "kapelusz","ziemniak","œciana",2,1,false,1,0 };
	zbiorek[74] = { "but","artyku³","woda",2,1,false,1,0 };
	zbiorek[75] = { "kwiat","zamek","stacja",3,1,false,1,0 };
	zbiorek[76] = { "ksiê¿yc","w³ókno","lina",3,1,false,1,0 };
	zbiorek[77] = { "mózg","korzeñ","kasa",6,1,false,1,0 };
	zbiorek[78] = { "obraz","cukier","luka",7,1,false,1,0 };
	zbiorek[79] = { "ogieñ","hotel","zabawa",3,1,false,1,0 };
	zbiorek[80] = { "stó³","film","kaczka",8,1,false,1,0 };
	zbiorek[81] = { "telefon","sklep","kawa",10,1,false,1,0 };
	zbiorek[82] = { "lew","kran","orkiestra",9,1,false,1,0 };
	zbiorek[83] = { "cieñ","klucz","koszula",3,1,false,1,0 };
	zbiorek[84] = { "kolczyk","tunel","s³owo",2,1,false,1,0 };
	zbiorek[85] = { "rower","kamieñ","wideo",13,1,false,1,0 };
	zbiorek[86] = { "bêben","wieniec","ciasto",12,1,false,1,0 };
	zbiorek[87] = { "cmentarz","kot","b³oto",5,1,false,1,0 };
	zbiorek[88] = { "guzik","taniec","kino",2,1,false,1,0 };
	zbiorek[89] = { "jêzyk","teatr","szk³o",6,1,false,1,0 };
	zbiorek[90] = { "koœció³","miœ","czo³o",5,1,false,1,0 };
	zbiorek[91] = { "miecz","czajnik","ucho",15,1,false,1,0 };
	zbiorek[92] = { "tron","list","z³oto",8,1,false,1,0 };
	zbiorek[93] = { "ci¹gnik","fortepian","srebro",13,1,false,1,0 };
	zbiorek[94] = { "ser","widelec","ŸdŸb³o",4,1,false,1,0 };
	zbiorek[95] = { "wielb³¹d","mê¿czyzna","lotnisko",9,1,false,1,0 };
	zbiorek[96] = { "gazeta","brama","olej",1,2,false,1,0 };
	zbiorek[97] = { "góra","œciana","ziemniak",3,2,false,1,0 };
	zbiorek[98] = { "kostka","woda","zamek",7,2,false,1,0 };
	zbiorek[99] = { "lalka","stacja","w³ókno",7,2,false,1,0 };
	zbiorek[100] = { "mapa","luka","artyku³",1,2,false,1,0 };
	zbiorek[101] = { "rakieta","kasa","korzeñ",13,2,false,1,0 };
	zbiorek[102] = { "wró¿ka","lina","kran",15,2,false,1,0 };
	zbiorek[103] = { "kobieta","zabawka","hotel",15,2,false,1,0 };
	zbiorek[104] = { "krowa","g³owa","film",9,2,false,1,0 };
	zbiorek[105] = { "flaga","kaczka","cukier",1,2,false,1,0 };
	zbiorek[106] = { "kukurydza","orkiestra","sklep",4,2,false,1,0 };
	zbiorek[107] = { "œwinia","koszula","klucz",9,2,false,1,0 };
	zbiorek[108] = { "butelka","kawa","cia³o",1,2,false,1,0 };
	zbiorek[109] = { "ryba","laska","wzgórze",9,2,false,1,0 };
	zbiorek[110] = { "gwiazda","szafa","ramiê",3,2,false,1,0 };
	zbiorek[111] = { "ksi¹¿ka","rzeka","wino",7,2,false,1,0 };
	zbiorek[112] = { "wie¿a","torebka","biurko",5,2,false,1,0 };
	zbiorek[113] = { "sieæ","mg³a","rondo",1,2,false,1,0 };
	zbiorek[114] = { "bomba","szko³a","œwiat³o",15,2,false,1,0 };
	zbiorek[115] = { "noga","fili¿anka","wiaderko",6,2,false,1,0 };
	zbiorek[116] = { "rêka","herbata","jedzenie",6,2,false ,1,0 };
	zbiorek[117] = { "noc","chata","bia³ko",3,2,false ,1,0 };
	zbiorek[118] = { "czekolada","kuchnia","ziarno",4,2,false,1,0 };
	zbiorek[119] = { "fabryka","bateria","ciastko",5,2,false ,1,0 };
	zbiorek[120] = { "¿elazko","s³owo","tunel",1,3,false ,1,0 };
	zbiorek[121] = { "jab³ko","wideo","kamieñ",4,3,false ,1,0 };
	zbiorek[122] = { "jezioro","kino","taniec",3,3,false ,1,0 };
	zbiorek[123] = { "krzes³o","ciasto","wieniec",8,3,false,1,0 };
	zbiorek[124] = { "skrzyd³o","b³oto","kot",6,3,false,1,0 };
	zbiorek[125] = { "mas³o","szk³o","teatr",4,3,false,1,0 };
	zbiorek[126] = { "okno","czo³o","list",8,3,false,1,0 };
	zbiorek[127] = { "radio","ucho","czajnik",10,3,false,1,0 };
	zbiorek[128] = { "akwarium","z³oto","miœ",1,3,false,1,0 };
	zbiorek[129] = { "lustro","srebro","fortepian",1,3,false,1,0 };
	zbiorek[130] = { "kiwi","cia³o","widelec",4,3,false,1,0 };
	zbiorek[131] = { "laboratorium","ciastko","mê¿czyzna",5,3,false,1,0 };
	zbiorek[132] = { "serce","bia³ko","g³owa",11,3,false ,1,0 };
	zbiorek[133] = { "miasto","wzgórze","laska",5,3,false ,1,0 };
	zbiorek[134] = { "³ó¿ko","ramiê","rzeka",8,3,false ,1,0 };
	zbiorek[135] = { "kolano","wino","szafa",6,3,false ,1,0 };
	zbiorek[136] = { "jajko","wiaderko","szko³a",4,3,false ,1,0 };
	zbiorek[137] = { "ko³o","œwiat³o","torebka",11,3,false ,1,0 };
	zbiorek[138] = { "miêso","biurko","fili¿anka",4,3,false ,1 ,0};
	zbiorek[139] = { "oko","rondo","mg³a",6,3,false ,1,0 };
	zbiorek[140] = { "s³oñce","jedzenie","herbata",3,3,false,1,0 };
	zbiorek[141] = { "myd³o","ziarno","chata",1,3,false ,1,0 };
	zbiorek[142] = { "wiêzienie","ŸdŸb³o","bateria",5,3,false,1,0 };
	zbiorek[143] = { "mleko","lotnisko","kuchnia",4,3,false ,1,0 };
	return zbiorek;
}
void wypisz_zbior(A zbiorek[])
{
	for (int i = 0; i < R; i++)
	{
		if (zbiorek[i].rodzaj == 1 && zbiorek[i].rodzaj_cong == 0)
			cout << i + 1 << ". " << zbiorek[i].slowo << " " << zbiorek[i].congruent_pasujacy << " " << zbiorek[i].kategoria << " MM " << endl;
		else if (zbiorek[i].rodzaj == 2 && zbiorek[i].rodzaj_cong == 0)
			cout << i + 1 << ". " << zbiorek[i].slowo << " " << zbiorek[i].congruent_pasujacy << " " << zbiorek[i].kategoria << " FF " << endl;
		else if (zbiorek[i].rodzaj == 3 && zbiorek[i].rodzaj_cong == 0)
			cout << i + 1 << ". " << zbiorek[i].slowo << " " << zbiorek[i].congruent_pasujacy << " " << zbiorek[i].kategoria << " NN " << endl;
		else if (zbiorek[i].rodzaj == 1 && zbiorek[i].rodzaj_cong == 2)
			cout << i + 1 << ". " << zbiorek[i].slowo << " " << zbiorek[i].congruent_niepasujacy << " " << zbiorek[i].kategoria << " MF " << endl;
		else if (zbiorek[i].rodzaj == 1 && zbiorek[i].rodzaj_cong == 3)
			cout << i + 1 << ". " << zbiorek[i].slowo << " " << zbiorek[i].congruent_niepasujacy << " " << zbiorek[i].kategoria << " MN " << endl;
		else if (zbiorek[i].rodzaj == 2 && zbiorek[i].rodzaj_cong == 1)
			cout << i + 1 << ". " << zbiorek[i].slowo << " " << zbiorek[i].congruent_niepasujacy << " " << zbiorek[i].kategoria << " FM " << endl;
		else if (zbiorek[i].rodzaj == 2 && zbiorek[i].rodzaj_cong == 3)
			cout << i + 1 << ". " << zbiorek[i].slowo << " " << zbiorek[i].congruent_niepasujacy << " " << zbiorek[i].kategoria << " FN " << endl;
		else if (zbiorek[i].rodzaj == 3 && zbiorek[i].rodzaj_cong == 1)
			cout << i + 1 << ". " << zbiorek[i].slowo << " " << zbiorek[i].congruent_niepasujacy << " " << zbiorek[i].kategoria << " NM " << endl;
		else if (zbiorek[i].rodzaj == 3 && zbiorek[i].rodzaj_cong == 2)
			cout << i + 1 << ". " << zbiorek[i].slowo << " " << zbiorek[i].congruent_niepasujacy << " " << zbiorek[i].kategoria << " NF " << endl;
	}
}


int main()
{
	A* zbiorek = new A[R];
	zbiorek=utworz_Zbior();													//create the set with all the words
	bool do_lista = true;
	A* listaA = new A[R];
	int ile_MM = 0;
	int ile_MF = 0;
	int ile_MN = 0;
	int ile_FF = 0;
	int ile_FN = 0;
	int ile_FM = 0;
	int ile_NN = 0;
	int ile_NM = 0;
	int ile_NF = 0;
	while (do_lista)
	{
		unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		srand(seed);														// Reseed the random number generator
		bool losowalne = true;
		cout <<endl<< "Start the draw" << endl;
		cout << seed << endl;
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
				if (time_span.count() > 1.33)									//if nothing is drawn for 2 seconds, break the loop and reset the list
				{
					cout << "Draw taken too long. Last position filled in list was: "<< i << "/" << R << endl;			//debugging help
					cout << "MM: " << ile_MM << " MF: " << ile_MF << " MN: " << ile_MN << " FF: " << ile_FF << " FN: " << ile_FN << " FM: " << ile_FM << " NN: " << ile_NN << " NM: " << ile_NM << " NF: " << ile_NF << endl;	//debugging help
					losowalne = false;
					ile_MM = 0;
					ile_MF = 0;
					ile_MN = 0;
					ile_FF = 0;
					ile_FN = 0;
					ile_FM = 0;
					ile_NN = 0;
					ile_NM = 0;
					ile_NF = 0;
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
				else if (i >= 3)											//checking all requirements for the drawn word depending if its 1st 2nd 3rd or other word in the list
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
					else if (zbiorek[los].rodzaj == 1 && zbiorek[los].rodzaj_cong == 0 && ile_MM >= 12)
						continue;
					else if (zbiorek[los].rodzaj == 1 && zbiorek[los].rodzaj_cong == 2 && ile_MF >= 6)
						continue;
					else if (zbiorek[los].rodzaj == 1 && zbiorek[los].rodzaj_cong == 3 && ile_MN >= 6)
						continue;
					else if (zbiorek[los].rodzaj == 2 && zbiorek[los].rodzaj_cong == 0 && ile_FF >= 12)
						continue;
					else if (zbiorek[los].rodzaj == 2 && zbiorek[los].rodzaj_cong == 1 && ile_FM >= 6)
						continue;
					else if (zbiorek[los].rodzaj == 2 && zbiorek[los].rodzaj_cong == 3 && ile_FN >= 6)
						continue;
					else if (zbiorek[los].rodzaj == 3 && zbiorek[los].rodzaj_cong == 0 && ile_NN >= 12)
						continue;
					else if (zbiorek[los].rodzaj == 3 && zbiorek[los].rodzaj_cong == 1 && ile_NM >= 6)
						continue;
					else if (zbiorek[los].rodzaj == 3 && zbiorek[los].rodzaj_cong == 2 && ile_NF >= 6)
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
						if (zbiorek[los].rodzaj == 1 && zbiorek[los].rodzaj_cong == 0)
							ile_MM++;
						else if (zbiorek[los].rodzaj == 1 && zbiorek[los].rodzaj_cong == 2)
							ile_MF++;
						else if (zbiorek[los].rodzaj == 1 && zbiorek[los].rodzaj_cong == 3)
							ile_MN++;
						else if (zbiorek[los].rodzaj == 2 && zbiorek[los].rodzaj_cong == 0)
							ile_FF++;
						else if (zbiorek[los].rodzaj == 2 && zbiorek[los].rodzaj_cong == 1)
							ile_FM++;
						else if (zbiorek[los].rodzaj == 2 && zbiorek[los].rodzaj_cong == 3)
							ile_FN++;
						else if (zbiorek[los].rodzaj == 3 && zbiorek[los].rodzaj_cong == 0)
							ile_NN++;
						else if (zbiorek[los].rodzaj == 3 && zbiorek[los].rodzaj_cong == 1)
							ile_NM++;
						else if (zbiorek[los].rodzaj == 3 && zbiorek[los].rodzaj_cong == 2)
							ile_NF++;
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
						if (zbiorek[los].rodzaj == 1 && zbiorek[los].rodzaj_cong == 0)
							ile_MM++;
						else if (zbiorek[los].rodzaj == 1 && zbiorek[los].rodzaj_cong == 2)
							ile_MF++;
						else if (zbiorek[los].rodzaj == 1 && zbiorek[los].rodzaj_cong == 3)
							ile_MN++;
						else if (zbiorek[los].rodzaj == 2 && zbiorek[los].rodzaj_cong == 0)
							ile_FF++;
						else if (zbiorek[los].rodzaj == 2 && zbiorek[los].rodzaj_cong == 1)
							ile_FM++;
						else if (zbiorek[los].rodzaj == 2 && zbiorek[los].rodzaj_cong == 3)
							ile_FN++;
						else if (zbiorek[los].rodzaj == 3 && zbiorek[los].rodzaj_cong == 0)
							ile_NN++;
						else if (zbiorek[los].rodzaj == 3 && zbiorek[los].rodzaj_cong == 1)
							ile_NM++;
						else if (zbiorek[los].rodzaj == 3 && zbiorek[los].rodzaj_cong == 2)
							ile_NF++;
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
					if (zbiorek[los].rodzaj == 1 && zbiorek[los].rodzaj_cong == 0)
						ile_MM++;
					else if (zbiorek[los].rodzaj == 1 && zbiorek[los].rodzaj_cong == 2)
						ile_MF++;
					else if (zbiorek[los].rodzaj == 1 && zbiorek[los].rodzaj_cong == 3)
						ile_MN++;
					else if (zbiorek[los].rodzaj == 2 && zbiorek[los].rodzaj_cong == 0)
						ile_FF++;
					else if (zbiorek[los].rodzaj == 2 && zbiorek[los].rodzaj_cong == 1)
						ile_FM++;
					else if (zbiorek[los].rodzaj == 2 && zbiorek[los].rodzaj_cong == 3)
						ile_FN++;
					else if (zbiorek[los].rodzaj == 3 && zbiorek[los].rodzaj_cong == 0)
						ile_NN++;
					else if (zbiorek[los].rodzaj == 3 && zbiorek[los].rodzaj_cong == 1)
						ile_NM++;
					else if (zbiorek[los].rodzaj == 3 && zbiorek[los].rodzaj_cong == 2)
						ile_NF++;
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
						if (zbiorek[los].rodzaj == 1 && zbiorek[los].rodzaj_cong == 0)
							ile_MM++;
						else if (zbiorek[los].rodzaj == 1 && zbiorek[los].rodzaj_cong == 2)
							ile_MF++;
						else if (zbiorek[los].rodzaj == 1 && zbiorek[los].rodzaj_cong == 3)
							ile_MN++;
						else if (zbiorek[los].rodzaj == 2 && zbiorek[los].rodzaj_cong == 0)
							ile_FF++;
						else if (zbiorek[los].rodzaj == 2 && zbiorek[los].rodzaj_cong == 1)
							ile_FM++;
						else if (zbiorek[los].rodzaj == 2 && zbiorek[los].rodzaj_cong == 3)
							ile_FN++;
						else if (zbiorek[los].rodzaj == 3 && zbiorek[los].rodzaj_cong == 0)
							ile_NN++;
						else if (zbiorek[los].rodzaj == 3 && zbiorek[los].rodzaj_cong == 1)
							ile_NM++;
						else if (zbiorek[los].rodzaj == 3 && zbiorek[los].rodzaj_cong == 2)
							ile_NF++;
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
	cout << endl << endl << endl << "Printing reversed list" << endl;
	wypisz_zbior(listaB);											//print the reversed list
	return 0;
}

//seed 191402056
//seed 3991666588