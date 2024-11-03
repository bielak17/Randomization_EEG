#include <iostream>
#include <string>
#include <list>
#include <chrono>
#include <fstream>

#define R 144

using namespace std;

struct A{
	string slowo;
	string congruent_pasujacy;
	string congruent_niepasujacy;
	int kategoria;					//1=everday 2=clothing 3=nature 4=food 5=place 6=body 7=ent 8=furniture 9=animal 10=device 11=shape 12=instrument 13=vehicle 14=material 15=other		
	int rodzaj;						//meski=1, zenski=2, nijaki=3
	int used;						//0 - not used, 1 - used in 1st half, 2 - used twice 3 - used 3 times 4 - used 4 times	
	bool congruent;					//true - congruent, false - incongruent
	int rodzaj_cong;				//cong pasujacy=0, meski=1, zenski=2, nijaki=3
	int ordinal = 1;				//1 in first 144 and 2 in second 144
};

A* utworz_Zbior() {
	A* set = new A[2*R];
	set[0] = { "kalendarz","olej","brama",1,1,false, 0,2 };
	set[1] = { "kapelusz","ziemniak","œciana",2,1,false,0,2 };
	set[2] = { "but","artyku³","woda",2,1,false,0,2 };
	set[3] = { "kwiat","zamek","stacja",3,1,false,0,2 };
	set[4] = { "ksiê¿yc","w³ókno","lina",3,1,false,0,2 };
	set[5] = { "mózg","korzeñ","kasa",6,1,false,0,2 };
	set[6] = { "obraz","cukier","luka",7,1,false,0,2 };
	set[7] = { "ogieñ","hotel","zabawa",3,1,false,0,2 };
	set[8] = { "stó³","film","kaczka",8,1,false,0,2 };
	set[9] = { "telefon","sklep","kawa",10,1,false,0,2 };
	set[10] = {"lew","kran","orkiestra",9,1,false,0,2};
	set[11] = { "cieñ","klucz","koszula",3,1,false,0,2 };
	set[12] = { "kolczyk","tunel","s³owo",2,1,false,0,3 };
	set[13] = { "rower","kamieñ","wideo",13,1,false,0 ,3};
	set[14] = { "bêben","wieniec","ciasto",12,1,false,0 ,3};
	set[15] = { "cmentarz","kot","b³oto",5,1,false,0,3 };
	set[16] = { "guzik","taniec","kino",2,1,false,0,3 };
	set[17] = { "jêzyk","teatr","szk³o",6,1,false,0,3 };
	set[18] = { "koœció³","miœ","czo³o",5,1,false,0,3 };
	set[19] = { "miecz","czajnik","ucho",15,1,false,0,3 };
	set[20] = { "tron","list","z³oto",8,1,false,0,3 };
	set[21] = { "ci¹gnik","fortepian","srebro",13,1,false,0,3 };
	set[22] = { "ser","widelec","ŸdŸb³o",4,1,false,0,3 };
	set[23] = { "wielb³¹d","mê¿czyzna","lotnisko",9,1,false,0,3 };
	set[24] = { "gazeta","brama","olej",1,2,false,0,1 };
	set[25] = { "góra","œciana","ziemniak",3,2,false,0,1 };
	set[26] = { "kostka","woda","zamek",7,2,false,0,1 };
	set[27] = { "lalka","stacja","w³ókno",7,2,false,0,1 };
	set[28] = { "mapa","luka","artyku³",1,2,false,0,1 };
	set[29] = { "rakieta","kasa","korzeñ",13,2,false,0,1 };
	set[30] = { "wró¿ka","lina","kran",15,2,false,0,1 };
	set[31] = { "kobieta","zabawka","hotel",15,2,false,0,1 };
	set[32] = { "krowa","g³owa","film",9,2,false,0,1 };
	set[33] = { "flaga","kaczka","cukier",1,2,false,0,1 };
	set[34] = { "kukurydza","orkiestra","sklep",4,2,false,0,1 };
	set[35] = { "œwinia","koszula","klucz",9,2,false,0,1 };
	set[36] = { "butelka","kawa","cia³o",1,2,false,0,3 };
	set[37] = { "ryba","laska","wzgórze",9,2,false,0,3 };
	set[38] = { "gwiazda","szafa","ramiê",3,2,false,0,3 };
	set[39] = { "ksi¹¿ka","rzeka","wino",7,2,false,0,3 };
	set[40] = { "wie¿a","torebka","biurko",5,2,false,0,3 };
	set[41] = { "sieæ","mg³a","rondo",1,2,false,0,3 };
	set[42] = { "bomba","szko³a","œwiat³o",15,2,false,0,3 };
	set[43] = { "noga","fili¿anka","wiaderko",6,2,false,0,3 };
	set[44] = { "rêka","herbata","jedzenie",6,2,false ,0,3};
	set[45] = { "noc","chata","bia³ko",3,2,false ,0,3};
	set[46] = { "czekolada","kuchnia","ziarno",4,2,false,0,3 };
	set[47] = { "fabryka","bateria","ciastko",5,2,false ,0,3};
	set[48] = { "¿elazko","s³owo","tunel",1,3,false ,0,1};
	set[49] = { "jab³ko","wideo","kamieñ",4,3,false ,0,1};
	set[50] = { "jezioro","kino","taniec",3,3,false ,0,1};
	set[51] = { "krzes³o","ciasto","wieniec",8,3,false,0,1 };
	set[52] = { "skrzyd³o","b³oto","kot",6,3,false,0,1 };
	set[53] = { "mas³o","szk³o","teatr",4,3,false,0,1 };
	set[54] = { "okno","czo³o","list",8,3,false,0,1 };
	set[55] = { "radio","ucho","czajnik",10,3,false,0,1 };
	set[56] = { "akwarium","z³oto","miœ",1,3,false,0,1 };
	set[57] = { "lustro","srebro","fortepian",1,3,false,0,1 };
	set[58] = { "kiwi","cia³o","widelec",4,3,false,0,1 };
	set[59] = { "laboratorium","ciastko","mê¿czyzna",5,3,false,0,1 };
	set[60] = { "serce","bia³ko","g³owa",11,3,false ,0,2};
	set[61] = { "miasto","wzgórze","laska",5,3,false ,0,2};
	set[62] = { "³ó¿ko","ramiê","rzeka",8,3,false ,0,2};
	set[63] = { "kolano","wino","szafa",6,3,false ,0,2};
	set[64] = { "jajko","wiaderko","szko³a",4,3,false ,0,2};
	set[65] = { "ko³o","œwiat³o","torebka",11,3,false ,0,2};
	set[66] = { "miêso","biurko","fili¿anka",4,3,false ,0,2};
	set[67] = { "oko","rondo","mg³a",6,3,false ,0,2};
	set[68] = { "s³oñce","jedzenie","herbata",3,3,false,0,2 };
	set[69] = { "myd³o","ziarno","chata",1,3,false ,0,2};
	set[70] = { "wiêzienie","ŸdŸb³o","bateria",5,3,false,0,2 };
	set[71] = { "mleko","lotnisko","kuchnia",4,3,false ,0,2};
	set[72] = { "kalendarz","olej","brama",1,1,false, 1,0 };
	set[73] = { "kapelusz","ziemniak","œciana",2,1,false,1,0 };
	set[74] = { "but","artyku³","woda",2,1,false,1,0 };
	set[75] = { "kwiat","zamek","stacja",3,1,false,1,0 };
	set[76] = { "ksiê¿yc","w³ókno","lina",3,1,false,1,0 };
	set[77] = { "mózg","korzeñ","kasa",6,1,false,1,0 };
	set[78] = { "obraz","cukier","luka",7,1,false,1,0 };
	set[79] = { "ogieñ","hotel","zabawa",3,1,false,1,0 };
	set[80] = { "stó³","film","kaczka",8,1,false,1,0 };
	set[81] = { "telefon","sklep","kawa",10,1,false,1,0 };
	set[82] = { "lew","kran","orkiestra",9,1,false,1,0 };
	set[83] = { "cieñ","klucz","koszula",3,1,false,1,0 };
	set[84] = { "kolczyk","tunel","s³owo",2,1,false,1,0 };
	set[85] = { "rower","kamieñ","wideo",13,1,false,1,0 };
	set[86] = { "bêben","wieniec","ciasto",12,1,false,1,0 };
	set[87] = { "cmentarz","kot","b³oto",5,1,false,1,0 };
	set[88] = { "guzik","taniec","kino",2,1,false,1,0 };
	set[89] = { "jêzyk","teatr","szk³o",6,1,false,1,0 };
	set[90] = { "koœció³","miœ","czo³o",5,1,false,1,0 };
	set[91] = { "miecz","czajnik","ucho",15,1,false,1,0 };
	set[92] = { "tron","list","z³oto",8,1,false,1,0 };
	set[93] = { "ci¹gnik","fortepian","srebro",13,1,false,1,0 };
	set[94] = { "ser","widelec","ŸdŸb³o",4,1,false,1,0 };
	set[95] = { "wielb³¹d","mê¿czyzna","lotnisko",9,1,false,1,0 };
	set[96] = { "gazeta","brama","olej",1,2,false,1,0 };
	set[97] = { "góra","œciana","ziemniak",3,2,false,1,0 };
	set[98] = { "kostka","woda","zamek",7,2,false,1,0 };
	set[99] = { "lalka","stacja","w³ókno",7,2,false,1,0 };
	set[100] = { "mapa","luka","artyku³",1,2,false,1,0 };
	set[101] = { "rakieta","kasa","korzeñ",13,2,false,1,0 };
	set[102] = { "wró¿ka","lina","kran",15,2,false,1,0 };
	set[103] = { "kobieta","zabawka","hotel",15,2,false,1,0 };
	set[104] = { "krowa","g³owa","film",9,2,false,1,0 };
	set[105] = { "flaga","kaczka","cukier",1,2,false,1,0 };
	set[106] = { "kukurydza","orkiestra","sklep",4,2,false,1,0 };
	set[107] = { "œwinia","koszula","klucz",9,2,false,1,0 };
	set[108] = { "butelka","kawa","cia³o",1,2,false,1,0 };
	set[109] = { "ryba","laska","wzgórze",9,2,false,1,0 };
	set[110] = { "gwiazda","szafa","ramiê",3,2,false,1,0 };
	set[111] = { "ksi¹¿ka","rzeka","wino",7,2,false,1,0 };
	set[112] = { "wie¿a","torebka","biurko",5,2,false,1,0 };
	set[113] = { "sieæ","mg³a","rondo",1,2,false,1,0 };
	set[114] = { "bomba","szko³a","œwiat³o",15,2,false,1,0 };
	set[115] = { "noga","fili¿anka","wiaderko",6,2,false,1,0 };
	set[116] = { "rêka","herbata","jedzenie",6,2,false ,1,0 };
	set[117] = { "noc","chata","bia³ko",3,2,false ,1,0 };
	set[118] = { "czekolada","kuchnia","ziarno",4,2,false,1,0 };
	set[119] = { "fabryka","bateria","ciastko",5,2,false ,1,0 };
	set[120] = { "¿elazko","s³owo","tunel",1,3,false ,1,0 };
	set[121] = { "jab³ko","wideo","kamieñ",4,3,false ,1,0 };
	set[122] = { "jezioro","kino","taniec",3,3,false ,1,0 };
	set[123] = { "krzes³o","ciasto","wieniec",8,3,false,1,0 };
	set[124] = { "skrzyd³o","b³oto","kot",6,3,false,1,0 };
	set[125] = { "mas³o","szk³o","teatr",4,3,false,1,0 };
	set[126] = { "okno","czo³o","list",8,3,false,1,0 };
	set[127] = { "radio","ucho","czajnik",10,3,false,1,0 };
	set[128] = { "akwarium","z³oto","miœ",1,3,false,1,0 };
	set[129] = { "lustro","srebro","fortepian",1,3,false,1,0 };
	set[130] = { "kiwi","cia³o","widelec",4,3,false,1,0 };
	set[131] = { "laboratorium","ciastko","mê¿czyzna",5,3,false,1,0 };
	set[132] = { "serce","bia³ko","g³owa",11,3,false ,1,0 };
	set[133] = { "miasto","wzgórze","laska",5,3,false ,1,0 };
	set[134] = { "³ó¿ko","ramiê","rzeka",8,3,false ,1,0 };
	set[135] = { "kolano","wino","szafa",6,3,false ,1,0 };
	set[136] = { "jajko","wiaderko","szko³a",4,3,false ,1,0 };
	set[137] = { "ko³o","œwiat³o","torebka",11,3,false ,1,0 };
	set[138] = { "miêso","biurko","fili¿anka",4,3,false ,1 ,0};
	set[139] = { "oko","rondo","mg³a",6,3,false ,1,0 };
	set[140] = { "s³oñce","jedzenie","herbata",3,3,false,1,0 };
	set[141] = { "myd³o","ziarno","chata",1,3,false ,1,0 };
	set[142] = { "wiêzienie","ŸdŸb³o","bateria",5,3,false,1,0 };
	set[143] = { "mleko","lotnisko","kuchnia",4,3,false ,1,0 };
	set[144] = { "kalendarz","olej","brama",1,1,false, 0,2,2 };
	set[145] = { "kapelusz","ziemniak","œciana",2,1,false,0,2,2 };
	set[146] = { "but","artyku³","woda",2,1,false,0,2,2 };
	set[147] = { "kwiat","zamek","stacja",3,1,false,0,2,2 };
	set[148] = { "ksiê¿yc","w³ókno","lina",3,1,false,0,2,2 };
	set[149] = { "mózg","korzeñ","kasa",6,1,false,0,2,2 };
	set[150] = { "obraz","cukier","luka",7,1,false,0,2,2 };
	set[151] = { "ogieñ","hotel","zabawa",3,1,false,0,2,2 };
	set[152] = { "stó³","film","kaczka",8,1,false,0,2,2 };
	set[153] = { "telefon","sklep","kawa",10,1,false,0,2,2 };
	set[154] = { "lew","kran","orkiestra",9,1,false,0,2,2 };
	set[155] = { "cieñ","klucz","koszula",3,1,false,0,2,2 };
	set[156] = { "kolczyk","tunel","s³owo",2,1,false,0,3,2 };
	set[157] = { "rower","kamieñ","wideo",13,1,false,0 ,3,2 };
	set[158] = { "bêben","wieniec","ciasto",12,1,false,0 ,3,2 };
	set[159] = { "cmentarz","kot","b³oto",5,1,false,0,3,2 };
	set[160] = { "guzik","taniec","kino",2,1,false,0,3,2 };
	set[161] = { "jêzyk","teatr","szk³o",6,1,false,0,3,2 };
	set[162] = { "koœció³","miœ","czo³o",5,1,false,0,3,2 };
	set[163] = { "miecz","czajnik","ucho",15,1,false,0,3,2 };
	set[164] = { "tron","list","z³oto",8,1,false,0,3,2 };
	set[165] = { "ci¹gnik","fortepian","srebro",13,1,false,0,3,2 };
	set[166] = { "ser","widelec","ŸdŸb³o",4,1,false,0,3,2 };
	set[167] = { "wielb³¹d","mê¿czyzna","lotnisko",9,1,false,0,3,2 };
	set[168] = { "gazeta","brama","olej",1,2,false,0,1,2 };
	set[169] = { "góra","œciana","ziemniak",3,2,false,0,1,2 };
	set[170] = { "kostka","woda","zamek",7,2,false,0,1,2 };
	set[171] = { "lalka","stacja","w³ókno",7,2,false,0,1,2 };
	set[172] = { "mapa","luka","artyku³",1,2,false,0,1,2 };
	set[173] = { "rakieta","kasa","korzeñ",13,2,false,0,1,2 };
	set[174] = { "wró¿ka","lina","kran",15,2,false,0,1,2 };
	set[175] = { "kobieta","zabawka","hotel",15,2,false,0,1,2 };
	set[176] = { "krowa","g³owa","film",9,2,false,0,1,2 };
	set[177] = { "flaga","kaczka","cukier",1,2,false,0,1,2 };
	set[178] = { "kukurydza","orkiestra","sklep",4,2,false,0,1,2 };
	set[179] = { "œwinia","koszula","klucz",9,2,false,0,1,2 };
	set[180] = { "butelka","kawa","cia³o",1,2,false,0,3,2 };
	set[181] = { "ryba","laska","wzgórze",9,2,false,0,3,2 };
	set[182] = { "gwiazda","szafa","ramiê",3,2,false,0,3,2 };
	set[183] = { "ksi¹¿ka","rzeka","wino",7,2,false,0,3,2 };
	set[184] = { "wie¿a","torebka","biurko",5,2,false,0,3,2 };
	set[185] = { "sieæ","mg³a","rondo",1,2,false,0,3,2 };
	set[186] = { "bomba","szko³a","œwiat³o",15,2,false,0,3,2 };
	set[187] = { "noga","fili¿anka","wiaderko",6,2,false,0,3,2 };
	set[188] = { "rêka","herbata","jedzenie",6,2,false ,0,3,2 };
	set[189] = { "noc","chata","bia³ko",3,2,false ,0,3,2 };
	set[190] = { "czekolada","kuchnia","ziarno",4,2,false,0,3,2 };
	set[191] = { "fabryka","bateria","ciastko",5,2,false ,0,3,2 };
	set[192] = { "¿elazko","s³owo","tunel",1,3,false ,0,1,2 };
	set[193] = { "jab³ko","wideo","kamieñ",4,3,false ,0,1,2 };
	set[194] = { "jezioro","kino","taniec",3,3,false ,0,1,2 };
	set[195] = { "krzes³o","ciasto","wieniec",8,3,false,0,1,2 };
	set[196] = { "skrzyd³o","b³oto","kot",6,3,false,0,1,2 };
	set[197] = { "mas³o","szk³o","teatr",4,3,false,0,1,2 };
	set[198] = { "okno","czo³o","list",8,3,false,0,1,2 };
	set[199] = { "radio","ucho","czajnik",10,3,false,0,1,2 };
	set[200] = { "akwarium","z³oto","miœ",1,3,false,0,1,2 };
	set[201] = { "lustro","srebro","fortepian",1,3,false,0,1,2 };
	set[202] = { "kiwi","cia³o","widelec",4,3,false,0,1,2 };
	set[203] = { "laboratorium","ciastko","mê¿czyzna",5,3,false,0,1,2 };
	set[204] = { "serce","bia³ko","g³owa",11,3,false ,0,2,2 };
	set[205] = { "miasto","wzgórze","laska",5,3,false ,0,2,2 };
	set[206] = { "³ó¿ko","ramiê","rzeka",8,3,false ,0,2,2 };
	set[207] = { "kolano","wino","szafa",6,3,false ,0,2,2 };
	set[208] = { "jajko","wiaderko","szko³a",4,3,false ,0,2,2 };
	set[209] = { "ko³o","œwiat³o","torebka",11,3,false ,0,2,2 };
	set[210] = { "miêso","biurko","fili¿anka",4,3,false ,0,2,2 };
	set[211] = { "oko","rondo","mg³a",6,3,false ,0,2,2 };
	set[212] = { "s³oñce","jedzenie","herbata",3,3,false,0,2,2 };
	set[213] = { "myd³o","ziarno","chata",1,3,false ,0,2,2 };
	set[214] = { "wiêzienie","ŸdŸb³o","bateria",5,3,false,0,2,2 };
	set[215] = { "mleko","lotnisko","kuchnia",4,3,false ,0,2,2 };
	set[216] = { "kalendarz","olej","brama",1,1,false, 1,0,2 };
	set[217] = { "kapelusz","ziemniak","œciana",2,1,false,1,0,2 };
	set[218] = { "but","artyku³","woda",2,1,false,1,0,2 };
	set[219] = { "kwiat","zamek","stacja",3,1,false,1,0,2 };
	set[220] = { "ksiê¿yc","w³ókno","lina",3,1,false,1,0,2 };
	set[221] = { "mózg","korzeñ","kasa",6,1,false,1,0,2 };
	set[222] = { "obraz","cukier","luka",7,1,false,1,0,2 };
	set[223] = { "ogieñ","hotel","zabawa",3,1,false,1,0,2 };
	set[224] = { "stó³","film","kaczka",8,1,false,1,0,2 };
	set[225] = { "telefon","sklep","kawa",10,1,false,1,0,2 };
	set[226] = { "lew","kran","orkiestra",9,1,false,1,0,2 };
	set[227] = { "cieñ","klucz","koszula",3,1,false,1,0,2 };
	set[228] = { "kolczyk","tunel","s³owo",2,1,false,1,0,2 };
	set[229] = { "rower","kamieñ","wideo",13,1,false,1,0,2 };
	set[230] = { "bêben","wieniec","ciasto",12,1,false,1,0,2 };
	set[231] = { "cmentarz","kot","b³oto",5,1,false,1,0,2 };
	set[232] = { "guzik","taniec","kino",2,1,false,1,0,2 };
	set[233] = { "jêzyk","teatr","szk³o",6,1,false,1,0,2 };
	set[234] = { "koœció³","miœ","czo³o",5,1,false,1,0,2 };
	set[235] = { "miecz","czajnik","ucho",15,1,false,1,0,2 };
	set[236] = { "tron","list","z³oto",8,1,false,1,0,2 };
	set[237] = { "ci¹gnik","fortepian","srebro",13,1,false,1,0,2 };
	set[238] = { "ser","widelec","ŸdŸb³o",4,1,false,1,0,2 };
	set[239] = { "wielb³¹d","mê¿czyzna","lotnisko",9,1,false,1,0,2 };
	set[240] = { "gazeta","brama","olej",1,2,false,1,0,2 };
	set[241] = { "góra","œciana","ziemniak",3,2,false,1,0,2 };
	set[242] = { "kostka","woda","zamek",7,2,false,1,0,2 };
	set[243] = { "lalka","stacja","w³ókno",7,2,false,1,0,2 };
	set[244] = { "mapa","luka","artyku³",1,2,false,1,0,2 };
	set[245] = { "rakieta","kasa","korzeñ",13,2,false,1,0,2 };
	set[246] = { "wró¿ka","lina","kran",15,2,false,1,0,2 };
	set[247] = { "kobieta","zabawka","hotel",15,2,false,1,0,2 };
	set[248] = { "krowa","g³owa","film",9,2,false,1,0,2 };
	set[249] = { "flaga","kaczka","cukier",1,2,false,1,0,2 };
	set[250] = { "kukurydza","orkiestra","sklep",4,2,false,1,0,2 };
	set[251] = { "œwinia","koszula","klucz",9,2,false,1,0,2 };
	set[252] = { "butelka","kawa","cia³o",1,2,false,1,0,2 };
	set[253] = { "ryba","laska","wzgórze",9,2,false,1,0,2 };
	set[254] = { "gwiazda","szafa","ramiê",3,2,false,1,0 ,2};
	set[255] = { "ksi¹¿ka","rzeka","wino",7,2,false,1,0,2 };
	set[256] = { "wie¿a","torebka","biurko",5,2,false,1,0,2 };
	set[257] = { "sieæ","mg³a","rondo",1,2,false,1,0,2 };
	set[258] = { "bomba","szko³a","œwiat³o",15,2,false,1,0,2 };
	set[259] = { "noga","fili¿anka","wiaderko",6,2,false,1,0,2 };
	set[260] = { "rêka","herbata","jedzenie",6,2,false ,1,0,2 };
	set[261] = { "noc","chata","bia³ko",3,2,false ,1,0,2 };
	set[262] = { "czekolada","kuchnia","ziarno",4,2,false,1,0,2 };
	set[263] = { "fabryka","bateria","ciastko",5,2,false ,1,0,2 };
	set[264] = { "¿elazko","s³owo","tunel",1,3,false ,1,0,2 };
	set[265] = { "jab³ko","wideo","kamieñ",4,3,false ,1,0,2 };
	set[266] = { "jezioro","kino","taniec",3,3,false ,1,0,2 };
	set[267] = { "krzes³o","ciasto","wieniec",8,3,false,1,0,2 };
	set[268] = { "skrzyd³o","b³oto","kot",6,3,false,1,0,2 };
	set[269] = { "mas³o","szk³o","teatr",4,3,false,1,0,2 };
	set[270] = { "okno","czo³o","list",8,3,false,1,0,2 };
	set[271] = { "radio","ucho","czajnik",10,3,false,1,0,2 };
	set[272] = { "akwarium","z³oto","miœ",1,3,false,1,0,2 };
	set[273] = { "lustro","srebro","fortepian",1,3,false,1,0,2 };
	set[274] = { "kiwi","cia³o","widelec",4,3,false,1,0,2 };
	set[275] = { "laboratorium","ciastko","mê¿czyzna",5,3,false,1,0,2 };
	set[276] = { "serce","bia³ko","g³owa",11,3,false ,1,0,2 };
	set[277] = { "miasto","wzgórze","laska",5,3,false ,1,0,2 };
	set[278] = { "³ó¿ko","ramiê","rzeka",8,3,false ,1,0,2 };
	set[279] = { "kolano","wino","szafa",6,3,false ,1,0,2 };
	set[280] = { "jajko","wiaderko","szko³a",4,3,false ,1,0,2 };
	set[281] = { "ko³o","œwiat³o","torebka",11,3,false ,1,0,2 };
	set[282] = { "miêso","biurko","fili¿anka",4,3,false ,1 ,0,2 };
	set[283] = { "oko","rondo","mg³a",6,3,false ,1,0,2 };
	set[284] = { "s³oñce","jedzenie","herbata",3,3,false,1,0,2 };
	set[285] = { "myd³o","ziarno","chata",1,3,false ,1,0,2 };
	set[286] = { "wiêzienie","ŸdŸb³o","bateria",5,3,false,1,0,2 };
	set[287] = { "mleko","lotnisko","kuchnia",4,3,false ,1,0,2 };
	return set;
}
void wypisz_zbior(A set[],ostream &out)
{
	for (int i = 0; i < R; i++)
	{
		if (set[i].rodzaj == 1 && set[i].rodzaj_cong == 0)
			out << i + 1 << ". " << set[i].slowo << " " << set[i].congruent_pasujacy << " " << set[i].kategoria << " MM " << endl;
		else if (set[i].rodzaj == 2 && set[i].rodzaj_cong == 0)
			out << i + 1 << ". " << set[i].slowo << " " << set[i].congruent_pasujacy << " " << set[i].kategoria << " FF " << endl;
		else if (set[i].rodzaj == 3 && set[i].rodzaj_cong == 0)
			out << i + 1 << ". " << set[i].slowo << " " << set[i].congruent_pasujacy << " " << set[i].kategoria << " NN " << endl;
		else if (set[i].rodzaj == 1 && set[i].rodzaj_cong == 2)
			out << i + 1 << ". " << set[i].slowo << " " << set[i].congruent_niepasujacy << " " << set[i].kategoria << " MF " << endl;
		else if (set[i].rodzaj == 1 && set[i].rodzaj_cong == 3)
			out << i + 1 << ". " << set[i].slowo << " " << set[i].congruent_niepasujacy << " " << set[i].kategoria << " MN " << endl;
		else if (set[i].rodzaj == 2 && set[i].rodzaj_cong == 1)
			out << i + 1 << ". " << set[i].slowo << " " << set[i].congruent_niepasujacy << " " << set[i].kategoria << " FM " << endl;
		else if (set[i].rodzaj == 2 && set[i].rodzaj_cong == 3)
			out << i + 1 << ". " << set[i].slowo << " " << set[i].congruent_niepasujacy << " " << set[i].kategoria << " FN " << endl;
		else if (set[i].rodzaj == 3 && set[i].rodzaj_cong == 1)
			out << i + 1 << ". " << set[i].slowo << " " << set[i].congruent_niepasujacy << " " << set[i].kategoria << " NM " << endl;
		else if (set[i].rodzaj == 3 && set[i].rodzaj_cong == 2)
			out << i + 1 << ". " << set[i].slowo << " " << set[i].congruent_niepasujacy << " " << set[i].kategoria << " NF " << endl;
	}
}




void Bare_noun_list()
{
	A* set = new A[R];
	set=utworz_Zbior();													//create the set with all the words
	bool do_list = true;
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
	while (do_list)
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
							set[j].used = 0;
					}
					break;
				}
				int los = rand() % R;										//draw a random number
				if (i >= 72)
				{
					if (set[los].used==2)
						continue;
					else if (lista[i - 2].congruent && lista[i - 1].congruent && set[los].congruent)
						continue;
					else if (!lista[i - 2].congruent && !lista[i - 1].congruent && !set[los].congruent)
						continue;
					else if (lista[i - 3].kategoria == set[los].kategoria || lista[i - 2].kategoria == set[los].kategoria || lista[i - 1].kategoria == set[los].kategoria)
						continue;
					else if (lista[i - 2].rodzaj == lista[i - 1].rodzaj && lista[i - 1].rodzaj == set[los].rodzaj)
						continue;
					else if (lista[i - 2].congruent && lista[i - 2].congruent_pasujacy == set[los].congruent_niepasujacy || lista[i - 1].congruent && lista[i - 1].congruent_pasujacy == set[los].congruent_niepasujacy)
						continue;
					else if (!lista[i - 2].congruent && lista[i - 2].congruent_niepasujacy == set[los].congruent_pasujacy || !lista[i - 1].congruent && lista[i - 1].congruent_niepasujacy == set[los].congruent_pasujacy)
						continue;
					else if (lista[i - 1].slowo.at(0) == set[los].slowo.at(0))
						continue;
					else
					{
						set[los].used = 2;
						lista[i] = set[los];
					}
				}
				else if (i >= 3)											//checking all requirements for the drawn word depending if its 1st 2nd 3rd or other word in the list
				{
					if (set[los].used)
						continue;
					else if (lista[i - 2].congruent && lista[i - 1].congruent && set[los].congruent)
						continue;
					else if (!lista[i - 2].congruent && !lista[i - 1].congruent && !set[los].congruent)
						continue;
					else if (lista[i - 3].kategoria == set[los].kategoria || lista[i - 2].kategoria == set[los].kategoria || lista[i - 1].kategoria == set[los].kategoria)
						continue;
					else if (lista[i - 2].rodzaj == lista[i - 1].rodzaj && lista[i - 1].rodzaj == set[los].rodzaj)
						continue;
					else if (lista[i - 2].congruent && lista[i - 2].congruent_pasujacy == set[los].congruent_niepasujacy || lista[i - 1].congruent && lista[i - 1].congruent_pasujacy == set[los].congruent_niepasujacy)
						continue;
					else if (!lista[i - 2].congruent && lista[i - 2].congruent_niepasujacy == set[los].congruent_pasujacy || !lista[i - 1].congruent && lista[i - 1].congruent_niepasujacy == set[los].congruent_pasujacy)
						continue;
					else if (lista[i - 1].slowo.at(0) == set[los].slowo.at(0))
						continue;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 0 && ile_MM >= 12)
						continue;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 2 && ile_MF >= 6)
						continue;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 3 && ile_MN >= 6)
						continue;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 0 && ile_FF >= 12)
						continue;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 1 && ile_FM >= 6)
						continue;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 3 && ile_FN >= 6)
						continue;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 0 && ile_NN >= 12)
						continue;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 1 && ile_NM >= 6)
						continue;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 2 && ile_NF >= 6)
						continue;
					else
					{
						if (los < 72)
						{
							set[los].used = 2;
							set[los + R / 2].used = 1;
							lista[i] = set[los];
						}
						else
						{
							set[los].used = 2;
							set[los - R / 2].used = 1;
							lista[i] = set[los];
						}
						if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 0)
							ile_MM++;
						else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 2)
							ile_MF++;
						else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 3)
							ile_MN++;
						else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 0)
							ile_FF++;
						else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 1)
							ile_FM++;
						else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 3)
							ile_FN++;
						else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 0)
							ile_NN++;
						else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 1)
							ile_NM++;
						else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 2)
							ile_NF++;
					}
				}
				else if (i == 2)
				{
					if (set[los].used)
						continue;
					else if (lista[i - 2].congruent && lista[i - 1].congruent && set[los].congruent)
						continue;
					else if (!lista[i - 2].congruent && !lista[i - 1].congruent && !set[los].congruent)
						continue;
					else if (lista[i - 2].rodzaj == lista[i - 1].rodzaj && lista[i - 1].rodzaj == set[los].rodzaj)
						continue;
					else if (lista[i - 2].congruent && lista[i - 2].congruent_pasujacy == set[los].congruent_niepasujacy || lista[i - 1].congruent && lista[i - 1].congruent_pasujacy == set[los].congruent_niepasujacy)
						continue;
					else if (!lista[i - 2].congruent && lista[i - 2].congruent_niepasujacy == set[los].congruent_pasujacy || !lista[i - 1].congruent && lista[i - 1].congruent_niepasujacy == set[los].congruent_pasujacy)
						continue;
					else if (lista[i - 1].slowo.at(0) == set[los].slowo.at(0))
						continue;
					else if (lista[i-2].kategoria == set[los].kategoria || lista[i-1].kategoria == set[los].kategoria)
						continue;
					else
					{
						if (los < 72)
						{
							set[los].used = 2;
							set[los + R / 2].used = 1;
							lista[i] = set[los];
						}
						else
						{
							set[los].used = 2;
							set[los - R / 2].used = 1;
							lista[i] = set[los];
						}
						if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 0)
							ile_MM++;
						else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 2)
							ile_MF++;
						else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 3)
							ile_MN++;
						else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 0)
							ile_FF++;
						else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 1)
							ile_FM++;
						else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 3)
							ile_FN++;
						else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 0)
							ile_NN++;
						else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 1)
							ile_NM++;
						else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 2)
							ile_NF++;
					}
				}
				else if (i == 0)
				{
					if (los < 72)
					{
						set[los].used = 2;
						set[los + R / 2].used = 1;
						lista[i] = set[los];
					}
					else
					{
						set[los].used = 2;
						set[los - R / 2].used = 1;
						lista[i] = set[los];
					}
					if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 0)
						ile_MM++;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 2)
						ile_MF++;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 3)
						ile_MN++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 0)
						ile_FF++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 1)
						ile_FM++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 3)
						ile_FN++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 0)
						ile_NN++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 1)
						ile_NM++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 2)
						ile_NF++;
				}
				else if (i == 1)
				{
					if (set[los].used)
						continue;
					else if (lista[i - 1].slowo.at(0) == set[los].slowo.at(0))
						continue;
					else if(lista[i-1].kategoria==set[los].kategoria)
						continue;
					else
					{
						if (los < 72)
						{
							set[los].used = 2;
							set[los + R / 2].used = 1;
							lista[i] = set[los];
						}
						else
						{
							set[los].used = 2;
							set[los - R / 2].used = 1;
							lista[i] = set[los];
						}
						if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 0)
							ile_MM++;
						else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 2)
							ile_MF++;
						else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 3)
							ile_MN++;
						else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 0)
							ile_FF++;
						else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 1)
							ile_FM++;
						else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 3)
							ile_FN++;
						else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 0)
							ile_NN++;
						else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 1)
							ile_NM++;
						else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 2)
							ile_NF++;
					}
				}
			}
		}
		if (lista[R - 1].used)										//if the last word is drawn, break the loop the list is set
		{
			do_list = false;
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
				if (set[i].used)									//reset the used flag
				{
					set[i].used = 0;
				}
			}
			delete[]lista;
		}
	}
	wypisz_zbior(listaA,cout);										//print the list
	A* listaB= new A[R];
	for (int i = 0; i < R; i++)										//create the reversed the list
	{
		listaB[R-i-1] = listaA[i];
	}
	cout << endl << endl << endl << "Printing reversed list" << endl;
	wypisz_zbior(listaB,cout);											//print the reversed list
	fstream out;
	out.open("lists_bare_noun.txt", ios::out);									//save the list to a file
	wypisz_zbior(listaA, out);
	out << "\n\n\n\Reversed list: " << endl;
	wypisz_zbior(listaB, out);
	out.close();
	delete[]listaA;
	delete[]listaB;
	return;
}




void noun_phrase_list()
{
	A* set = new A[2*R];
	set = utworz_Zbior();													//create the set with all the words
	bool do_list = true;
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
	int ile_1 = 0;
	int ile_2 = 0;
	while (do_list)
	{
		unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		srand(seed);														// Reseed the random number generator
		bool losowalne = true;
		cout << endl << "Start the draw" << endl;
		cout << seed << endl;
		A* lista = new A[2*R];
		for (int i = 0; i < 2*R; i++)
		{
			lista[i].used = 0;
		}
		for (int i = 0; i < 2 * R; i++)
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
					cout << "Draw taken too long. Last position filled in list was: " << i << "/" << 2 * R << endl;			//debugging help
					cout << "Not fully filled quarter stats:" << endl;
					cout << "MM: " << ile_MM << " MF: " << ile_MF << " MN: " << ile_MN << " FF: " << ile_FF << " FN: " << ile_FN << " FM: " << ile_FM << " NN: " << ile_NN << " NM: " << ile_NM << " NF: " << ile_NF << " 1: " << ile_1 << " 2: " << ile_2 << endl;	//debugging help
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
					ile_1 = 0;
					ile_2 = 0;
					for (int j = 0; j < 2 * R; j++)
					{													//reset the used flag
							set[j].used = 0;
					}
					break;
				}
				int los = rand() % (2 * R);										//draw a random number
				if (i == 0)												//just assigning word to the list and changing used flags of the same word but with different form and ordinal it will be used all the time when adding new word to generated list
				{
					if (los < 72)
					{
						set[los].used = 4;
						set[los + R / 2].used = 1;
						set[los + R].used = 1;
						set[los + 3 * R / 2].used = 1;
						lista[i] = set[los];
					}
					else if(los<144)
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los + R / 2].used = 1;
						set[los + R].used = 1;
						lista[i] = set[los];
					}
					else if (los < 216)
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los + R / 2].used = 1;
						set[los - R].used = 1;
						lista[i] = set[los];
					}
					else
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los - R].used = 1;
						set[los - 3 * R / 2].used = 1;
						lista[i] = set[los];
					}
					set[los].ordinal==1 ? ile_1++ : ile_2++;
					if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 0)
						ile_MM++;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 2)
						ile_MF++;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 3)
						ile_MN++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 0)
						ile_FF++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 1)
						ile_FM++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 3)
						ile_FN++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 0)
						ile_NN++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 1)
						ile_NM++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 2)
						ile_NF++;
				}
				if (i == 1)														//checking 1st letter and category if ok add to the list
				{
					if (set[los].used)
						continue;
					else if (lista[i - 1].slowo.at(0) == set[los].slowo.at(0))
						continue;
					else if (lista[i - 1].kategoria == set[los].kategoria)
						continue;
					if (los < 72)
					{
						set[los].used = 4;
						set[los + R / 2].used = 1;
						set[los + R].used = 1;
						set[los + 3 * R / 2].used = 1;
						lista[i] = set[los];
					}
					else if (los < 144)
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los + R / 2].used = 1;
						set[los + R].used = 1;
						lista[i] = set[los];
					}
					else if (los < 216)
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los + R / 2].used = 1;
						set[los - R].used = 1;
						lista[i] = set[los];
					}
					else
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los - R].used = 1;
						set[los - 3 * R / 2].used = 1;
						lista[i] = set[los];
					}
					set[los].ordinal == 1 ? ile_1++ : ile_2++;
					if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 0)
						ile_MM++;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 2)
						ile_MF++;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 3)
						ile_MN++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 0)
						ile_FF++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 1)
						ile_FM++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 3)
						ile_FN++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 0)
						ile_NN++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 1)
						ile_NM++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 2)
						ile_NF++;
				}
				if (i == 2)													//checking almost all requirements if ok add to the list
				{
					if (set[los].used)
						continue;
					else if (lista[i - 2].congruent && lista[i - 1].congruent && set[los].congruent)
						continue;
					else if (!lista[i - 2].congruent && !lista[i - 1].congruent && !set[los].congruent)
						continue;
					else if (lista[i - 2].rodzaj == lista[i - 1].rodzaj && lista[i - 1].rodzaj == set[los].rodzaj)
						continue;
					else if (lista[i - 2].congruent && lista[i - 2].congruent_pasujacy == set[los].congruent_niepasujacy || lista[i - 1].congruent && lista[i - 1].congruent_pasujacy == set[los].congruent_niepasujacy)
						continue;
					else if (!lista[i - 2].congruent && lista[i - 2].congruent_niepasujacy == set[los].congruent_pasujacy || !lista[i - 1].congruent && lista[i - 1].congruent_niepasujacy == set[los].congruent_pasujacy)
						continue;
					else if (lista[i - 1].slowo.at(0) == set[los].slowo.at(0))
						continue;
					else if (lista[i - 2].kategoria == set[los].kategoria || lista[i - 1].kategoria == set[los].kategoria)
						continue;
					else if (lista[i - 2].ordinal == set[los].ordinal && lista[i - 1].ordinal == set[los].ordinal)
						continue;
					if (los < 72)
					{
						set[los].used = 4;
						set[los + R / 2].used = 1;
						set[los + R].used = 1;
						set[los + 3 * R / 2].used = 1;
						lista[i] = set[los];
					}
					else if (los < 144)
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los + R / 2].used = 1;
						set[los + R].used = 1;
						lista[i] = set[los];
					}
					else if (los < 216)
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los + R / 2].used = 1;
						set[los - R].used = 1;
						lista[i] = set[los];
					}
					else
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los - R].used = 1;
						set[los - 3 * R / 2].used = 1;
						lista[i] = set[los];
					}
					set[los].ordinal == 1 ? ile_1++ : ile_2++;
					if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 0)
						ile_MM++;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 2)
						ile_MF++;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 3)
						ile_MN++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 0)
						ile_FF++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 1)
						ile_FM++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 3)
						ile_FN++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 0)
						ile_NN++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 1)
						ile_NM++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 2)
						ile_NF++;
				}
				if (i >= 3 && i < 72)											//checking all requirements and adding to the list if ok
				{
					if (set[los].used)
						continue;
					else if (lista[i - 2].congruent && lista[i - 1].congruent && set[los].congruent)
						continue;
					else if (!lista[i - 2].congruent && !lista[i - 1].congruent && !set[los].congruent)
						continue;
					else if (lista[i - 3].kategoria == set[los].kategoria || lista[i - 2].kategoria == set[los].kategoria || lista[i - 1].kategoria == set[los].kategoria)
						continue;
					else if (lista[i - 2].rodzaj == lista[i - 1].rodzaj && lista[i - 1].rodzaj == set[los].rodzaj)
						continue;
					else if (lista[i - 2].congruent && lista[i - 2].congruent_pasujacy == set[los].congruent_niepasujacy || lista[i - 1].congruent && lista[i - 1].congruent_pasujacy == set[los].congruent_niepasujacy)
						continue;
					else if (!lista[i - 2].congruent && lista[i - 2].congruent_niepasujacy == set[los].congruent_pasujacy || !lista[i - 1].congruent && lista[i - 1].congruent_niepasujacy == set[los].congruent_pasujacy)
						continue;
					else if (lista[i - 1].slowo.at(0) == set[los].slowo.at(0))
						continue;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 0 && ile_MM >= 12)
						continue;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 2 && ile_MF >= 6)
						continue;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 3 && ile_MN >= 6)
						continue;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 0 && ile_FF >= 12)
						continue;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 1 && ile_FM >= 6)
						continue;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 3 && ile_FN >= 6)
						continue;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 0 && ile_NN >= 12)
						continue;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 1 && ile_NM >= 6)
						continue;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 2 && ile_NF >= 6)
						continue;
					else if (set[los].ordinal == 1 && ile_1 >= 36)
						continue;
					else if (set[los].ordinal == 2 && ile_2 >= 36)
						continue;
					else if (lista[i - 2].ordinal == set[los].ordinal && lista[i - 1].ordinal == set[los].ordinal)
						continue;
					if (los < 72)
					{
						set[los].used = 4;
						set[los + R / 2].used = 1;
						set[los + R].used = 1;
						set[los + 3 * R / 2].used = 1;
						lista[i] = set[los];
					}
					else if (los < 144)
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los + R / 2].used = 1;
						set[los + R].used = 1;
						lista[i] = set[los];
					}
					else if (los < 216)
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los + R / 2].used = 1;
						set[los - R].used = 1;
						lista[i] = set[los];
					}
					else
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los - R].used = 1;
						set[los - 3 * R / 2].used = 1;
						lista[i] = set[los];
					}
					set[los].ordinal == 1 ? ile_1++ : ile_2++;
					if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 0)
						ile_MM++;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 2)
						ile_MF++;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 3)
						ile_MN++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 0)
						ile_FF++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 1)
						ile_FM++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 3)
						ile_FN++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 0)
						ile_NN++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 1)
						ile_NM++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 2)
						ile_NF++;
				}
				if (i >= 72 && i < 144)													//drawing 2nd quarter now used flag will be set as 2 and we are checking if flag is less than 2 everything else the same as in 1st
				{
					if (i == 72)
					{
						cout << "1st quarter stats:" << endl;					//printing stats of the previous quarter and reseting variables used to count things
						cout << "MM: " << ile_MM << " MF: " << ile_MF << " MN: " << ile_MN << " FF: " << ile_FF << " FN: " << ile_FN << " FM: " << ile_FM << " NN: " << ile_NN << " NM: " << ile_NM << " NF: " << ile_NF << " 1: " << ile_1 << " 2: " << ile_2 << endl;
						ile_MM = 0;
						ile_MF = 0;
						ile_MN = 0;
						ile_FF = 0;
						ile_FN = 0;
						ile_FM = 0;
						ile_NN = 0;
						ile_NM = 0;
						ile_NF = 0;
						ile_1 = 0;
						ile_2 = 0;
					}
					if (set[los].used<2)
						continue;
					else if (lista[i - 2].congruent && lista[i - 1].congruent && set[los].congruent)
						continue;
					else if (!lista[i - 2].congruent && !lista[i - 1].congruent && !set[los].congruent)
						continue;
					else if (lista[i - 3].kategoria == set[los].kategoria || lista[i - 2].kategoria == set[los].kategoria || lista[i - 1].kategoria == set[los].kategoria)
						continue;
					else if (lista[i - 2].rodzaj == lista[i - 1].rodzaj && lista[i - 1].rodzaj == set[los].rodzaj)
						continue;
					else if (lista[i - 2].congruent && lista[i - 2].congruent_pasujacy == set[los].congruent_niepasujacy || lista[i - 1].congruent && lista[i - 1].congruent_pasujacy == set[los].congruent_niepasujacy)
						continue;
					else if (!lista[i - 2].congruent && lista[i - 2].congruent_niepasujacy == set[los].congruent_pasujacy || !lista[i - 1].congruent && lista[i - 1].congruent_niepasujacy == set[los].congruent_pasujacy)
						continue;
					else if (lista[i - 1].slowo.at(0) == set[los].slowo.at(0))
						continue;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 0 && ile_MM >= 12)
						continue;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 2 && ile_MF >= 6)
						continue;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 3 && ile_MN >= 6)
						continue;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 0 && ile_FF >= 12)
						continue;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 1 && ile_FM >= 6)
						continue;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 3 && ile_FN >= 6)
						continue;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 0 && ile_NN >= 12)
						continue;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 1 && ile_NM >= 6)
						continue;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 2 && ile_NF >= 6)
						continue;
					else if (set[los].ordinal == 1 && ile_1 >= 36)
						continue;
					else if (set[los].ordinal == 2 && ile_2 >= 36)
						continue;
					else if (lista[i - 2].ordinal == set[los].ordinal && lista[i - 1].ordinal == set[los].ordinal)
						continue;
					if (los < 72)
					{
						set[los].used = 4;
						if(set[los + R / 2].used==1) set[los + R / 2].used = 2;
						if(set[los + R].used==1) set[los + R].used = 2;
						if(set[los + 3 * R / 2].used==1) set[los + 3 * R / 2].used = 2;
						lista[i] = set[los];
					}
					else if (los < 144)
					{
						set[los].used = 4;
						if (set[los + R / 2].used == 1) set[los + R / 2].used = 2;
						if (set[los + R].used == 1) set[los + R].used = 2;
						if (set[los - R / 2].used == 1) set[los + 3 * R / 2].used = 2;
						lista[i] = set[los];
					}
					else if (los < 216)
					{
						set[los].used = 4;
						if (set[los + R / 2].used == 1) set[los + R / 2].used = 2;
						if (set[los - R].used == 1) set[los + R].used = 2;
						if (set[los - R / 2].used == 1) set[los + 3 * R / 2].used = 2;
						lista[i] = set[los];
					}
					else
					{
						set[los].used = 4;
						if (set[los - R / 2].used == 1) set[los + R / 2].used = 2;
						if (set[los - R].used == 1) set[los + R].used = 2;
						if (set[los - 3 * R / 2].used == 1) set[los + 3 * R / 2].used = 2;
						lista[i] = set[los];
					}
					set[los].ordinal == 1 ? ile_1++ : ile_2++;
					if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 0)
						ile_MM++;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 2)
						ile_MF++;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 3)
						ile_MN++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 0)
						ile_FF++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 1)
						ile_FM++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 3)
						ile_FN++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 0)
						ile_NN++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 1)
						ile_NM++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 2)
						ile_NF++;
				}
				if (i >= 144 && i < 216)													//drawing 3rd quarter now used flag will be set as 3 and we are checking if flag is less than 3 everything else the same as in 1st adn 2nd 
				{
					if (i == 144)
					{
						cout << "2nd quarter stats:" << endl;
						cout << "MM: " << ile_MM << " MF: " << ile_MF << " MN: " << ile_MN << " FF: " << ile_FF << " FN: " << ile_FN << " FM: " << ile_FM << " NN: " << ile_NN << " NM: " << ile_NM << " NF: " << ile_NF << " 1: " << ile_1 << " 2: " << ile_2 << endl;
						ile_MM = 0;
						ile_MF = 0;
						ile_MN = 0;
						ile_FF = 0;
						ile_FN = 0;
						ile_FM = 0;
						ile_NN = 0;
						ile_NM = 0;
						ile_NF = 0;
						ile_1 = 0;
						ile_2 = 0;
					}
					if (set[los].used < 3)
						continue;
					else if (lista[i - 2].congruent && lista[i - 1].congruent && set[los].congruent)
						continue;
					else if (!lista[i - 2].congruent && !lista[i - 1].congruent && !set[los].congruent)
						continue;
					else if (lista[i - 3].kategoria == set[los].kategoria || lista[i - 2].kategoria == set[los].kategoria || lista[i - 1].kategoria == set[los].kategoria)
						continue;
					else if (lista[i - 2].rodzaj == lista[i - 1].rodzaj && lista[i - 1].rodzaj == set[los].rodzaj)
						continue;
					else if (lista[i - 2].congruent && lista[i - 2].congruent_pasujacy == set[los].congruent_niepasujacy || lista[i - 1].congruent && lista[i - 1].congruent_pasujacy == set[los].congruent_niepasujacy)
						continue;
					else if (!lista[i - 2].congruent && lista[i - 2].congruent_niepasujacy == set[los].congruent_pasujacy || !lista[i - 1].congruent && lista[i - 1].congruent_niepasujacy == set[los].congruent_pasujacy)
						continue;
					else if (lista[i - 1].slowo.at(0) == set[los].slowo.at(0))
						continue;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 0 && ile_MM >= 12)
						continue;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 2 && ile_MF >= 6)
						continue;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 3 && ile_MN >= 6)
						continue;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 0 && ile_FF >= 12)
						continue;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 1 && ile_FM >= 6)
						continue;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 3 && ile_FN >= 6)
						continue;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 0 && ile_NN >= 12)
						continue;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 1 && ile_NM >= 6)
						continue;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 2 && ile_NF >= 6)
						continue;
					else if (set[los].ordinal == 1 && ile_1 >= 36)
						continue;
					else if (set[los].ordinal == 2 && ile_2 >= 36)
						continue;
					else if (lista[i - 2].ordinal == set[los].ordinal && lista[i - 1].ordinal == set[los].ordinal)
						continue;
					if (los < 72)
					{
						set[los].used = 4;
						if (set[los + R / 2].used == 2) set[los + R / 2].used = 2;
						if (set[los + R].used == 2) set[los + R].used = 2;
						if (set[los + 3 * R / 2].used == 2) set[los + 3 * R / 2].used = 2;
						lista[i] = set[los];
					}
					else if (los < 144)
					{
						set[los].used = 4;
						if (set[los + R / 2].used == 2) set[los + R / 2].used = 2;
						if (set[los + R].used == 2) set[los + R].used = 2;
						if (set[los - R / 2].used == 2) set[los + 3 * R / 2].used = 2;
						lista[i] = set[los];
					}
					else if (los < 216)
					{
						set[los].used = 4;
						if (set[los + R / 2].used == 2) set[los + R / 2].used = 2;
						if (set[los - R].used == 2) set[los + R].used = 2;
						if (set[los - R / 2].used == 2) set[los + 3 * R / 2].used = 2;
						lista[i] = set[los];
					}
					else
					{
						set[los].used = 4;
						if (set[los - R / 2].used == 2) set[los + R / 2].used = 2;
						if (set[los - R].used == 2) set[los + R].used = 2;
						if (set[los - 3 * R / 2].used == 2) set[los + 3 * R / 2].used = 2;
						lista[i] = set[los];
					}
					set[los].ordinal == 1 ? ile_1++ : ile_2++;
					if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 0)
						ile_MM++;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 2)
						ile_MF++;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 3)
						ile_MN++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 0)
						ile_FF++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 1)
						ile_FM++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 3)
						ile_FN++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 0)
						ile_NN++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 1)
						ile_NM++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 2)
						ile_NF++;
				}
				if (i >= 216)														//drawing last quarter now used flag will be set as 4 = done and other words flags wont be changed because they were already used everything else the same as in other quarters
				{
					if (i == 144)
					{
						cout << "3rd quarter stats:" << endl;
					cout << "MM: " << ile_MM << " MF: " << ile_MF << " MN: " << ile_MN << " FF: " << ile_FF << " FN: " << ile_FN << " FM: " << ile_FM << " NN: " << ile_NN << " NM: " << ile_NM << " NF: " << ile_NF << " 1: " << ile_1 << " 2: " << ile_2 << endl;
						ile_MM = 0;
						ile_MF = 0;
						ile_MN = 0;
						ile_FF = 0;
						ile_FN = 0;
						ile_FM = 0;
						ile_NN = 0;
						ile_NM = 0;
						ile_NF = 0;
						ile_1 = 0;
						ile_2 = 0;
					}
					if (set[los].used < 4)
					continue;
					else if (lista[i - 2].congruent && lista[i - 1].congruent && set[los].congruent)
					continue;
					else if (!lista[i - 2].congruent && !lista[i - 1].congruent && !set[los].congruent)
						continue;
					else if (lista[i - 3].kategoria == set[los].kategoria || lista[i - 2].kategoria == set[los].kategoria || lista[i - 1].kategoria == set[los].kategoria)
						continue;
					else if (lista[i - 2].rodzaj == lista[i - 1].rodzaj && lista[i - 1].rodzaj == set[los].rodzaj)
						continue;
					else if (lista[i - 2].congruent && lista[i - 2].congruent_pasujacy == set[los].congruent_niepasujacy || lista[i - 1].congruent && lista[i - 1].congruent_pasujacy == set[los].congruent_niepasujacy)
						continue;
					else if (!lista[i - 2].congruent && lista[i - 2].congruent_niepasujacy == set[los].congruent_pasujacy || !lista[i - 1].congruent && lista[i - 1].congruent_niepasujacy == set[los].congruent_pasujacy)
						continue;
					else if (lista[i - 1].slowo.at(0) == set[los].slowo.at(0))
						continue;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 0 && ile_MM >= 12)
						continue;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 2 && ile_MF >= 6)
						continue;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 3 && ile_MN >= 6)
						continue;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 0 && ile_FF >= 12)
						continue;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 1 && ile_FM >= 6)
						continue;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 3 && ile_FN >= 6)
						continue;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 0 && ile_NN >= 12)
						continue;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 1 && ile_NM >= 6)
						continue;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 2 && ile_NF >= 6)
						continue;
					else if (set[los].ordinal == 1 && ile_1 >= 36)
						continue;
					else if (set[los].ordinal == 2 && ile_2 >= 36)
						continue;
					else if (lista[i - 2].ordinal == set[los].ordinal && lista[i - 1].ordinal == set[los].ordinal)
						continue;
					if (los < 72)
					{
						set[los].used = 4;
						lista[i] = set[los];
					}
					else if (los < 144)
					{
						set[los].used = 4;
						lista[i] = set[los];
					}
					else if (los < 216)
					{
						set[los].used = 4;
						lista[i] = set[los];
					}
					else
					{
						set[los].used = 4;
						lista[i] = set[los];
					}
					set[los].ordinal == 1 ? ile_1++ : ile_2++;
					if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 0)
						ile_MM++;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 2)
						ile_MF++;
					else if (set[los].rodzaj == 1 && set[los].rodzaj_cong == 3)
						ile_MN++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 0)
						ile_FF++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 1)
						ile_FM++;
					else if (set[los].rodzaj == 2 && set[los].rodzaj_cong == 3)
						ile_FN++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 0)
						ile_NN++;
					else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 1)
						ile_NM++;
				else if (set[los].rodzaj == 3 && set[los].rodzaj_cong == 2)
						ile_NF++;
				}
			}
		}
		if (lista[2*R - 1].used)										//if the last word is drawn, break the loop the list is set
		{
			do_list = false;
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
				if (set[i].used)									//reset the used flag
				{
					set[i].used = 0;
				}
			}
			delete[]lista;
		}
	}
	wypisz_zbior(listaA, cout);
	fstream out;
	out.open("lists_noun_phrase.txt", ios::out);									//save the list to a file
	wypisz_zbior(listaA, out);
	out.close();
	delete[]listaA;
	return;
}

//For better chance to generate 2nd task might need to add checkpoints after each quarter and save used flags and drawn quarters somewhere and load them before each try

int main()
{
	noun_phrase_list();
	//Bare_noun_list();
	return 0;
}