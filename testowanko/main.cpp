#include <iostream>
#include <string>
#include <list>
#include <chrono>
#include <fstream>

#define R 144

using namespace std;

struct A {
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
	A* set = new A[2 * R];
	set[0] = { "kalendarz","olej","brama",1,1,false, 0,2 };
	set[1] = { "kapelusz","ziemniak","ściana",2,1,false,0,2 };
	set[2] = { "but","artykuł","woda",2,1,false,0,2 };
	set[3] = { "kwiat","zamek","stacja",3,1,false,0,2 };
	set[4] = { "księżyc","włókno","lina",3,1,false,0,2 };
	set[5] = { "mózg","korzeń","kasa",6,1,false,0,2 };
	set[6] = { "obraz","cukier","luka",7,1,false,0,2 };
	set[7] = { "ogień","hotel","zabawa",3,1,false,0,2 };
	set[8] = { "stół","film","kaczka",8,1,false,0,2 };
	set[9] = { "telefon","sklep","kawa",10,1,false,0,2 };
	set[10] = { "lew","kran","orkiestra",9,1,false,0,2 };
	set[11] = { "cień","klucz","koszula",3,1,false,0,2 };
	set[12] = { "kolczyk","tunel","słowo",2,1,false,0,3 };
	set[13] = { "rower","kamień","wideo",13,1,false,0 ,3 };
	set[14] = { "bęben","wieniec","ciasto",12,1,false,0 ,3 };
	set[15] = { "cmentarz","kot","błoto",5,1,false,0,3 };
	set[16] = { "guzik","taniec","kino",2,1,false,0,3 };
	set[17] = { "język","teatr","szkło",6,1,false,0,3 };
	set[18] = { "kościół","miś","czoło",5,1,false,0,3 };
	set[19] = { "miecz","czajnik","ucho",15,1,false,0,3 };
	set[20] = { "tron","list","złoto",8,1,false,0,3 };
	set[21] = { "ciągnik","fortepian","srebro",13,1,false,0,3 };
	set[22] = { "ser","widelec","źdźbło",4,1,false,0,3 };
	set[23] = { "wielbłąd","mężczyzna","lotnisko",9,1,false,0,3 };
	set[24] = { "gazeta","brama","olej",1,2,false,0,1 };
	set[25] = { "góra","ściana","ziemniak",3,2,false,0,1 };
	set[26] = { "kostka","woda","zamek",7,2,false,0,1 };
	set[27] = { "lalka","stacja","włókno",7,2,false,0,1 };
	set[28] = { "mapa","luka","artykuł",1,2,false,0,1 };
	set[29] = { "rakieta","kasa","korzeń",13,2,false,0,1 };
	set[30] = { "wróżka","lina","kran",15,2,false,0,1 };
	set[31] = { "kobieta","zabawka","hotel",15,2,false,0,1 };
	set[32] = { "krowa","głowa","film",9,2,false,0,1 };
	set[33] = { "flaga","kaczka","cukier",1,2,false,0,1 };
	set[34] = { "kukurydza","orkiestra","sklep",4,2,false,0,1 };
	set[35] = { "świnia","koszula","klucz",9,2,false,0,1 };
	set[36] = { "butelka","kawa","ciało",1,2,false,0,3 };
	set[37] = { "ryba","laska","wzgórze",9,2,false,0,3 };
	set[38] = { "gwiazda","szafa","ramię",3,2,false,0,3 };
	set[39] = { "książka","rzeka","wino",7,2,false,0,3 };
	set[40] = { "wieża","torebka","biurko",5,2,false,0,3 };
	set[41] = { "sieć","mgła","rondo",1,2,false,0,3 };
	set[42] = { "bomba","szkoła","światło",15,2,false,0,3 };
	set[43] = { "noga","filiżanka","wiaderko",6,2,false,0,3 };
	set[44] = { "ręka","herbata","jedzenie",6,2,false ,0,3 };
	set[45] = { "noc","chata","białko",3,2,false ,0,3 };
	set[46] = { "czekolada","kuchnia","ziarno",4,2,false,0,3 };
	set[47] = { "fabryka","bateria","ciastko",5,2,false ,0,3 };
	set[48] = { "żelazko","słowo","tunel",1,3,false ,0,1 };
	set[49] = { "jabłko","wideo","kamień",4,3,false ,0,1 };
	set[50] = { "jezioro","kino","taniec",3,3,false ,0,1 };
	set[51] = { "krzesło","ciasto","wieniec",8,3,false,0,1 };
	set[52] = { "skrzydło","błoto","kot",6,3,false,0,1 };
	set[53] = { "masło","szkło","teatr",4,3,false,0,1 };
	set[54] = { "okno","czoło","list",8,3,false,0,1 };
	set[55] = { "radio","ucho","czajnik",10,3,false,0,1 };
	set[56] = { "akwarium","złoto","miś",1,3,false,0,1 };
	set[57] = { "lustro","srebro","fortepian",1,3,false,0,1 };
	set[58] = { "kiwi","ciało","widelec",4,3,false,0,1 };
	set[59] = { "laboratorium","ciastko","mężczyzna",5,3,false,0,1 };
	set[60] = { "serce","białko","głowa",11,3,false ,0,2 };
	set[61] = { "miasto","wzgórze","laska",5,3,false ,0,2 };
	set[62] = { "łóżko","ramię","rzeka",8,3,false ,0,2 };
	set[63] = { "kolano","wino","szafa",6,3,false ,0,2 };
	set[64] = { "jajko","wiaderko","szkoła",4,3,false ,0,2 };
	set[65] = { "koło","światło","torebka",11,3,false ,0,2 };
	set[66] = { "mięso","biurko","filiżanka",4,3,false ,0,2 };
	set[67] = { "oko","rondo","mgła",6,3,false ,0,2 };
	set[68] = { "słońce","jedzenie","herbata",3,3,false,0,2 };
	set[69] = { "mydło","ziarno","chata",1,3,false ,0,2 };
	set[70] = { "więzienie","źdźbło","bateria",5,3,false,0,2 };
	set[71] = { "mleko","lotnisko","kuchnia",4,3,false ,0,2 };
	set[72] = { "kalendarz","olej","brama",1,1,false, 1,0 };
	set[73] = { "kapelusz","ziemniak","ściana",2,1,false,1,0 };
	set[74] = { "but","artykuł","woda",2,1,false,1,0 };
	set[75] = { "kwiat","zamek","stacja",3,1,false,1,0 };
	set[76] = { "księżyc","włókno","lina",3,1,false,1,0 };
	set[77] = { "mózg","korzeń","kasa",6,1,false,1,0 };
	set[78] = { "obraz","cukier","luka",7,1,false,1,0 };
	set[79] = { "ogień","hotel","zabawa",3,1,false,1,0 };
	set[80] = { "stół","film","kaczka",8,1,false,1,0 };
	set[81] = { "telefon","sklep","kawa",10,1,false,1,0 };
	set[82] = { "lew","kran","orkiestra",9,1,false,1,0 };
	set[83] = { "cień","klucz","koszula",3,1,false,1,0 };
	set[84] = { "kolczyk","tunel","słowo",2,1,false,1,0 };
	set[85] = { "rower","kamień","wideo",13,1,false,1,0 };
	set[86] = { "bęben","wieniec","ciasto",12,1,false,1,0 };
	set[87] = { "cmentarz","kot","błoto",5,1,false,1,0 };
	set[88] = { "guzik","taniec","kino",2,1,false,1,0 };
	set[89] = { "język","teatr","szkło",6,1,false,1,0 };
	set[90] = { "kościół","miś","czoło",5,1,false,1,0 };
	set[91] = { "miecz","czajnik","ucho",15,1,false,1,0 };
	set[92] = { "tron","list","złoto",8,1,false,1,0 };
	set[93] = { "ciągnik","fortepian","srebro",13,1,false,1,0 };
	set[94] = { "ser","widelec","źdźbło",4,1,false,1,0 };
	set[95] = { "wielbłąd","mężczyzna","lotnisko",9,1,false,1,0 };
	set[96] = { "gazeta","brama","olej",1,2,false,1,0 };
	set[97] = { "góra","ściana","ziemniak",3,2,false,1,0 };
	set[98] = { "kostka","woda","zamek",7,2,false,1,0 };
	set[99] = { "lalka","stacja","włókno",7,2,false,1,0 };
	set[100] = { "mapa","luka","artykuł",1,2,false,1,0 };
	set[101] = { "rakieta","kasa","korzeń",13,2,false,1,0 };
	set[102] = { "wróżka","lina","kran",15,2,false,1,0 };
	set[103] = { "kobieta","zabawka","hotel",15,2,false,1,0 };
	set[104] = { "krowa","głowa","film",9,2,false,1,0 };
	set[105] = { "flaga","kaczka","cukier",1,2,false,1,0 };
	set[106] = { "kukurydza","orkiestra","sklep",4,2,false,1,0 };
	set[107] = { "świnia","koszula","klucz",9,2,false,1,0 };
	set[108] = { "butelka","kawa","ciało",1,2,false,1,0 };
	set[109] = { "ryba","laska","wzgórze",9,2,false,1,0 };
	set[110] = { "gwiazda","szafa","ramię",3,2,false,1,0 };
	set[111] = { "książka","rzeka","wino",7,2,false,1,0 };
	set[112] = { "wieża","torebka","biurko",5,2,false,1,0 };
	set[113] = { "sieć","mgła","rondo",1,2,false,1,0 };
	set[114] = { "bomba","szkoła","światło",15,2,false,1,0 };
	set[115] = { "noga","filiżanka","wiaderko",6,2,false,1,0 };
	set[116] = { "ręka","herbata","jedzenie",6,2,false ,1,0 };
	set[117] = { "noc","chata","białko",3,2,false ,1,0 };
	set[118] = { "czekolada","kuchnia","ziarno",4,2,false,1,0 };
	set[119] = { "fabryka","bateria","ciastko",5,2,false ,1,0 };
	set[120] = { "żelazko","słowo","tunel",1,3,false ,1,0 };
	set[121] = { "jabłko","wideo","kamień",4,3,false ,1,0 };
	set[122] = { "jezioro","kino","taniec",3,3,false ,1,0 };
	set[123] = { "krzesło","ciasto","wieniec",8,3,false,1,0 };
	set[124] = { "skrzydło","błoto","kot",6,3,false,1,0 };
	set[125] = { "masło","szkło","teatr",4,3,false,1,0 };
	set[126] = { "okno","czoło","list",8,3,false,1,0 };
	set[127] = { "radio","ucho","czajnik",10,3,false,1,0 };
	set[128] = { "akwarium","złoto","miś",1,3,false,1,0 };
	set[129] = { "lustro","srebro","fortepian",1,3,false,1,0 };
	set[130] = { "kiwi","ciało","widelec",4,3,false,1,0 };
	set[131] = { "laboratorium","ciastko","mężczyzna",5,3,false,1,0 };
	set[132] = { "serce","białko","głowa",11,3,false ,1,0 };
	set[133] = { "miasto","wzgórze","laska",5,3,false ,1,0 };
	set[134] = { "łóżko","ramię","rzeka",8,3,false ,1,0 };
	set[135] = { "kolano","wino","szafa",6,3,false ,1,0 };
	set[136] = { "jajko","wiaderko","szkoła",4,3,false ,1,0 };
	set[137] = { "koło","światło","torebka",11,3,false ,1,0 };
	set[138] = { "mięso","biurko","filiżanka",4,3,false ,1 ,0 };
	set[139] = { "oko","rondo","mgła",6,3,false ,1,0 };
	set[140] = { "słońce","jedzenie","herbata",3,3,false,1,0 };
	set[141] = { "mydło","ziarno","chata",1,3,false ,1,0 };
	set[142] = { "więzienie","źdźbło","bateria",5,3,false,1,0 };
	set[143] = { "mleko","lotnisko","kuchnia",4,3,false ,1,0 };
	set[144] = { "kalendarz","olej","brama",1,1,false, 0,2,2 };
	set[145] = { "kapelusz","ziemniak","ściana",2,1,false,0,2,2 };
	set[146] = { "but","artykuł","woda",2,1,false,0,2,2 };
	set[147] = { "kwiat","zamek","stacja",3,1,false,0,2,2 };
	set[148] = { "księżyc","włókno","lina",3,1,false,0,2,2 };
	set[149] = { "mózg","korzeń","kasa",6,1,false,0,2,2 };
	set[150] = { "obraz","cukier","luka",7,1,false,0,2,2 };
	set[151] = { "ogień","hotel","zabawa",3,1,false,0,2,2 };
	set[152] = { "stół","film","kaczka",8,1,false,0,2,2 };
	set[153] = { "telefon","sklep","kawa",10,1,false,0,2,2 };
	set[154] = { "lew","kran","orkiestra",9,1,false,0,2,2 };
	set[155] = { "cień","klucz","koszula",3,1,false,0,2,2 };
	set[156] = { "kolczyk","tunel","słowo",2,1,false,0,3,2 };
	set[157] = { "rower","kamień","wideo",13,1,false,0 ,3,2 };
	set[158] = { "bęben","wieniec","ciasto",12,1,false,0 ,3,2 };
	set[159] = { "cmentarz","kot","błoto",5,1,false,0,3,2 };
	set[160] = { "guzik","taniec","kino",2,1,false,0,3,2 };
	set[161] = { "język","teatr","szkło",6,1,false,0,3,2 };
	set[162] = { "kościół","miś","czoło",5,1,false,0,3,2 };
	set[163] = { "miecz","czajnik","ucho",15,1,false,0,3,2 };
	set[164] = { "tron","list","złoto",8,1,false,0,3,2 };
	set[165] = { "ciągnik","fortepian","srebro",13,1,false,0,3,2 };
	set[166] = { "ser","widelec","źdźbło",4,1,false,0,3,2 };
	set[167] = { "wielbłąd","mężczyzna","lotnisko",9,1,false,0,3,2 };
	set[168] = { "gazeta","brama","olej",1,2,false,0,1,2 };
	set[169] = { "góra","ściana","ziemniak",3,2,false,0,1,2 };
	set[170] = { "kostka","woda","zamek",7,2,false,0,1,2 };
	set[171] = { "lalka","stacja","włókno",7,2,false,0,1,2 };
	set[172] = { "mapa","luka","artykuł",1,2,false,0,1,2 };
	set[173] = { "rakieta","kasa","korzeń",13,2,false,0,1,2 };
	set[174] = { "wróżka","lina","kran",15,2,false,0,1,2 };
	set[175] = { "kobieta","zabawka","hotel",15,2,false,0,1,2 };
	set[176] = { "krowa","głowa","film",9,2,false,0,1,2 };
	set[177] = { "flaga","kaczka","cukier",1,2,false,0,1,2 };
	set[178] = { "kukurydza","orkiestra","sklep",4,2,false,0,1,2 };
	set[179] = { "świnia","koszula","klucz",9,2,false,0,1,2 };
	set[180] = { "butelka","kawa","ciało",1,2,false,0,3,2 };
	set[181] = { "ryba","laska","wzgórze",9,2,false,0,3,2 };
	set[182] = { "gwiazda","szafa","ramię",3,2,false,0,3,2 };
	set[183] = { "książka","rzeka","wino",7,2,false,0,3,2 };
	set[184] = { "wieża","torebka","biurko",5,2,false,0,3,2 };
	set[185] = { "sieć","mgła","rondo",1,2,false,0,3,2 };
	set[186] = { "bomba","szkoła","światło",15,2,false,0,3,2 };
	set[187] = { "noga","filiżanka","wiaderko",6,2,false,0,3,2 };
	set[188] = { "ręka","herbata","jedzenie",6,2,false ,0,3,2 };
	set[189] = { "noc","chata","białko",3,2,false ,0,3,2 };
	set[190] = { "czekolada","kuchnia","ziarno",4,2,false,0,3,2 };
	set[191] = { "fabryka","bateria","ciastko",5,2,false ,0,3,2 };
	set[192] = { "żelazko","słowo","tunel",1,3,false ,0,1,2 };
	set[193] = { "jabłko","wideo","kamień",4,3,false ,0,1,2 };
	set[194] = { "jezioro","kino","taniec",3,3,false ,0,1,2 };
	set[195] = { "krzesło","ciasto","wieniec",8,3,false,0,1,2 };
	set[196] = { "skrzydło","błoto","kot",6,3,false,0,1,2 };
	set[197] = { "masło","szkło","teatr",4,3,false,0,1,2 };
	set[198] = { "okno","czoło","list",8,3,false,0,1,2 };
	set[199] = { "radio","ucho","czajnik",10,3,false,0,1,2 };
	set[200] = { "akwarium","złoto","miś",1,3,false,0,1,2 };
	set[201] = { "lustro","srebro","fortepian",1,3,false,0,1,2 };
	set[202] = { "kiwi","ciało","widelec",4,3,false,0,1,2 };
	set[203] = { "laboratorium","ciastko","mężczyzna",5,3,false,0,1,2 };
	set[204] = { "serce","białko","głowa",11,3,false ,0,2,2 };
	set[205] = { "miasto","wzgórze","laska",5,3,false ,0,2,2 };
	set[206] = { "łóżko","ramię","rzeka",8,3,false ,0,2,2 };
	set[207] = { "kolano","wino","szafa",6,3,false ,0,2,2 };
	set[208] = { "jajko","wiaderko","szkoła",4,3,false ,0,2,2 };
	set[209] = { "koło","światło","torebka",11,3,false ,0,2,2 };
	set[210] = { "mięso","biurko","filiżanka",4,3,false ,0,2,2 };
	set[211] = { "oko","rondo","mgła",6,3,false ,0,2,2 };
	set[212] = { "słońce","jedzenie","herbata",3,3,false,0,2,2 };
	set[213] = { "mydło","ziarno","chata",1,3,false ,0,2,2 };
	set[214] = { "więzienie","źdźbło","bateria",5,3,false,0,2,2 };
	set[215] = { "mleko","lotnisko","kuchnia",4,3,false ,0,2,2 };
	set[216] = { "kalendarz","olej","brama",1,1,false, 1,0,2 };
	set[217] = { "kapelusz","ziemniak","ściana",2,1,false,1,0,2 };
	set[218] = { "but","artykuł","woda",2,1,false,1,0,2 };
	set[219] = { "kwiat","zamek","stacja",3,1,false,1,0,2 };
	set[220] = { "księżyc","włókno","lina",3,1,false,1,0,2 };
	set[221] = { "mózg","korzeń","kasa",6,1,false,1,0,2 };
	set[222] = { "obraz","cukier","luka",7,1,false,1,0,2 };
	set[223] = { "ogień","hotel","zabawa",3,1,false,1,0,2 };
	set[224] = { "stół","film","kaczka",8,1,false,1,0,2 };
	set[225] = { "telefon","sklep","kawa",10,1,false,1,0,2 };
	set[226] = { "lew","kran","orkiestra",9,1,false,1,0,2 };
	set[227] = { "cień","klucz","koszula",3,1,false,1,0,2 };
	set[228] = { "kolczyk","tunel","słowo",2,1,false,1,0,2 };
	set[229] = { "rower","kamień","wideo",13,1,false,1,0,2 };
	set[230] = { "bęben","wieniec","ciasto",12,1,false,1,0,2 };
	set[231] = { "cmentarz","kot","błoto",5,1,false,1,0,2 };
	set[232] = { "guzik","taniec","kino",2,1,false,1,0,2 };
	set[233] = { "język","teatr","szkło",6,1,false,1,0,2 };
	set[234] = { "kościół","miś","czoło",5,1,false,1,0,2 };
	set[235] = { "miecz","czajnik","ucho",15,1,false,1,0,2 };
	set[236] = { "tron","list","złoto",8,1,false,1,0,2 };
	set[237] = { "ciągnik","fortepian","srebro",13,1,false,1,0,2 };
	set[238] = { "ser","widelec","źdźbło",4,1,false,1,0,2 };
	set[239] = { "wielbłąd","mężczyzna","lotnisko",9,1,false,1,0,2 };
	set[240] = { "gazeta","brama","olej",1,2,false,1,0,2 };
	set[241] = { "góra","ściana","ziemniak",3,2,false,1,0,2 };
	set[242] = { "kostka","woda","zamek",7,2,false,1,0,2 };
	set[243] = { "lalka","stacja","włókno",7,2,false,1,0,2 };
	set[244] = { "mapa","luka","artykuł",1,2,false,1,0,2 };
	set[245] = { "rakieta","kasa","korzeń",13,2,false,1,0,2 };
	set[246] = { "wróżka","lina","kran",15,2,false,1,0,2 };
	set[247] = { "kobieta","zabawka","hotel",15,2,false,1,0,2 };
	set[248] = { "krowa","głowa","film",9,2,false,1,0,2 };
	set[249] = { "flaga","kaczka","cukier",1,2,false,1,0,2 };
	set[250] = { "kukurydza","orkiestra","sklep",4,2,false,1,0,2 };
	set[251] = { "świnia","koszula","klucz",9,2,false,1,0,2 };
	set[252] = { "butelka","kawa","ciało",1,2,false,1,0,2 };
	set[253] = { "ryba","laska","wzgórze",9,2,false,1,0,2 };
	set[254] = { "gwiazda","szafa","ramię",3,2,false,1,0 ,2 };
	set[255] = { "książka","rzeka","wino",7,2,false,1,0,2 };
	set[256] = { "wieża","torebka","biurko",5,2,false,1,0,2 };
	set[257] = { "sieć","mgła","rondo",1,2,false,1,0,2 };
	set[258] = { "bomba","szkoła","światło",15,2,false,1,0,2 };
	set[259] = { "noga","filiżanka","wiaderko",6,2,false,1,0,2 };
	set[260] = { "ręka","herbata","jedzenie",6,2,false ,1,0,2 };
	set[261] = { "noc","chata","białko",3,2,false ,1,0,2 };
	set[262] = { "czekolada","kuchnia","ziarno",4,2,false,1,0,2 };
	set[263] = { "fabryka","bateria","ciastko",5,2,false ,1,0,2 };
	set[264] = { "żelazko","słowo","tunel",1,3,false ,1,0,2 };
	set[265] = { "jabłko","wideo","kamień",4,3,false ,1,0,2 };
	set[266] = { "jezioro","kino","taniec",3,3,false ,1,0,2 };
	set[267] = { "krzesło","ciasto","wieniec",8,3,false,1,0,2 };
	set[268] = { "skrzydło","błoto","kot",6,3,false,1,0,2 };
	set[269] = { "masło","szkło","teatr",4,3,false,1,0,2 };
	set[270] = { "okno","czoło","list",8,3,false,1,0,2 };
	set[271] = { "radio","ucho","czajnik",10,3,false,1,0,2 };
	set[272] = { "akwarium","złoto","miś",1,3,false,1,0,2 };
	set[273] = { "lustro","srebro","fortepian",1,3,false,1,0,2 };
	set[274] = { "kiwi","ciało","widelec",4,3,false,1,0,2 };
	set[275] = { "laboratorium","ciastko","mężczyzna",5,3,false,1,0,2 };
	set[276] = { "serce","białko","głowa",11,3,false ,1,0,2 };
	set[277] = { "miasto","wzgórze","laska",5,3,false ,1,0,2 };
	set[278] = { "łóżko","ramię","rzeka",8,3,false ,1,0,2 };
	set[279] = { "kolano","wino","szafa",6,3,false ,1,0,2 };
	set[280] = { "jajko","wiaderko","szkoła",4,3,false ,1,0,2 };
	set[281] = { "koło","światło","torebka",11,3,false ,1,0,2 };
	set[282] = { "mięso","biurko","filiżanka",4,3,false ,1 ,0,2 };
	set[283] = { "oko","rondo","mgła",6,3,false ,1,0,2 };
	set[284] = { "słońce","jedzenie","herbata",3,3,false,1,0,2 };
	set[285] = { "mydło","ziarno","chata",1,3,false ,1,0,2 };
	set[286] = { "więzienie","źdźbło","bateria",5,3,false,1,0,2 };
	set[287] = { "mleko","lotnisko","kuchnia",4,3,false ,1,0,2 };
	return set;
}
void wypisz_zbior(A set[], ostream& out, int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
	{
		if (set[i].rodzaj == 1 && set[i].rodzaj_cong == 0)
			out << i + 1 << ". " << set[i].slowo << " " << set[i].congruent_pasujacy << " " << set[i].kategoria << " MM " << " " << set[i].ordinal << endl;
		else if (set[i].rodzaj == 2 && set[i].rodzaj_cong == 0)
			out << i + 1 << ". " << set[i].slowo << " " << set[i].congruent_pasujacy << " " << set[i].kategoria << " FF " << " " << set[i].ordinal << endl;
		else if (set[i].rodzaj == 3 && set[i].rodzaj_cong == 0)
			out << i + 1 << ". " << set[i].slowo << " " << set[i].congruent_pasujacy << " " << set[i].kategoria << " NN " << " " << set[i].ordinal << endl;
		else if (set[i].rodzaj == 1 && set[i].rodzaj_cong == 2)
			out << i + 1 << ". " << set[i].slowo << " " << set[i].congruent_niepasujacy << " " << set[i].kategoria << " MF " << " " << set[i].ordinal << endl;
		else if (set[i].rodzaj == 1 && set[i].rodzaj_cong == 3)
			out << i + 1 << ". " << set[i].slowo << " " << set[i].congruent_niepasujacy << " " << set[i].kategoria << " MN " << " " << set[i].ordinal << endl;
		else if (set[i].rodzaj == 2 && set[i].rodzaj_cong == 1)
			out << i + 1 << ". " << set[i].slowo << " " << set[i].congruent_niepasujacy << " " << set[i].kategoria << " FM " << " " << set[i].ordinal << endl;
		else if (set[i].rodzaj == 2 && set[i].rodzaj_cong == 3)
			out << i + 1 << ". " << set[i].slowo << " " << set[i].congruent_niepasujacy << " " << set[i].kategoria << " FN " << " " << set[i].ordinal << endl;
		else if (set[i].rodzaj == 3 && set[i].rodzaj_cong == 1)
			out << i + 1 << ". " << set[i].slowo << " " << set[i].congruent_niepasujacy << " " << set[i].kategoria << " NM " << " " << set[i].ordinal << endl;
		else if (set[i].rodzaj == 3 && set[i].rodzaj_cong == 2)
			out << i + 1 << ". " << set[i].slowo << " " << set[i].congruent_niepasujacy << " " << set[i].kategoria << " NF " << " " << set[i].ordinal << endl;
	}
}




void Bare_noun_list()
{
	cout << "Generating list for bare noun task." << endl;
	A* set = new A[R];
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
	bool half = false;
	int used_flags[R];
	A* saved_list = new A[R];
	while (do_list)
	{
		unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		srand(seed);														// Reseed the random number generator
		bool losowalne = true;
		cout << endl << "Start the draw" << endl;
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
					cout << "Draw taken too long. Last position filled in list was: " << i << "/" << R << endl;			//debugging help
					if (!half)
					{
						cout << "MM: " << ile_MM << " MF: " << ile_MF << " MN: " << ile_MN << " FF: " << ile_FF << " FN: " << ile_FN << " FM: " << ile_FM << " NN: " << ile_NN << " NM: " << ile_NM << " NF: " << ile_NF << endl;	//debugging help
						ile_MM = 0;
						ile_MF = 0;
						ile_MN = 0;
						ile_FF = 0;
						ile_FN = 0;
						ile_FM = 0;
						ile_NN = 0;
						ile_NM = 0;
						ile_NF = 0;
					}
					losowalne = false;
					break;
				}
				if (i == 0 && half)
				{
					for (int i = 0; i < R; i++)
					{
						lista[i] = saved_list[i];
						set[i].used = used_flags[i];
					}
					i = R / 2;
					cout << "Loaded 1st half" << endl;
				}
				int los = rand() % R;										//draw a random number
				if (i >= 72)
				{
					if (!half)
					{
						cout << "1st quarter stats:" << endl;					//printing stats of the previous quarter and reseting variables used to count things
						cout << "MM: " << ile_MM << " MF: " << ile_MF << " MN: " << ile_MN << " FF: " << ile_FF << " FN: " << ile_FN << " FM: " << ile_FM << " NN: " << ile_NN << " NM: " << ile_NM << " NF: " << ile_NF << endl;
						ile_MM = 0;
						ile_MF = 0;
						ile_MN = 0;
						ile_FF = 0;
						ile_FN = 0;
						ile_FM = 0;
						ile_NN = 0;
						ile_NM = 0;
						ile_NF = 0;
						cout << "Saving progress" << endl;
						for (int j = 0; j < R; j++)								//saving the list and used flags
						{
							saved_list[j] = lista[j];
							used_flags[j] = set[j].used;
						}
						half = true;
					}
					if (set[los].used == 2)
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
					else if (lista[i - 2].kategoria == set[los].kategoria || lista[i - 1].kategoria == set[los].kategoria)
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
					else if (lista[i - 1].kategoria == set[los].kategoria)
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
	cout << "Word   |   Distractor   |   Category   |   Type   |   Ordinal" << endl << endl << endl;
	wypisz_zbior(listaA, cout, R);										//print the list
	A* listaB = new A[R];
	for (int i = 0; i < R; i++)										//create the reversed the list
	{
		listaB[R - i - 1] = listaA[i];
	}
	cout << endl << endl << endl << "Printing reversed list" << endl;
	wypisz_zbior(listaB, cout, R);											//print the reversed list
	fstream out;
	out.open("lists_bare_noun.txt", ios::out);									//save the list to a file
	out << "Word   |   Distractor   |   Category   |   Type   |   Ordinal" << endl << endl << endl;
	wypisz_zbior(listaA, out, R);
	out << "\n\n\nReversed list: " << endl;
	wypisz_zbior(listaB, out, R);
	out.close();
	delete[]listaA;
	delete[]listaB;
	cout << "\nGenerating list for bare noun task finished." << endl << endl << endl;
	return;
}




void noun_phrase_list()
{
	cout << "\nGenerating list for noun phrase task." << endl;
	A* set = new A[2 * R];
	set = utworz_Zbior();													//create the set with all the words
	bool do_list = true;
	A* listaA = new A[2 * R];
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
	bool Q1 = 0;
	bool Q2 = 0;
	bool Q3 = 0;
	A* saved_list = new A[2 * R];
	int used_flags[2 * R];
	while (do_list)
	{
		unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		srand(seed);														// Reseed the random number generator
		bool losowalne = true;
		cout << endl << "Start the draw" << endl;
		cout << seed << endl;
		A* lista = new A[2 * R];
		for (int i = 0; i < 2 * R; i++)
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
				if ((time_span.count() > 1.33 && !Q2) || (Q2 && time_span.count() > 3.0))						//if nothing is drawn for 2 seconds, break the loop and reset the list
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
				if (i == 0 && Q1)
				{
					for (int i = 0; i < 2 * R; i++)
					{
						lista[i] = saved_list[i];
						set[i].used = used_flags[i];
					}
					i = R / 2;
					cout << "Loaded 1st quarter" << endl;
				}
				else if (i == 0 && Q2)
				{
					for (int i = 0; i < 2 * R; i++)
					{
						lista[i] = saved_list[i];
						set[i].used = used_flags[i];
					}
					i = R;
					cout << "Loaded two quarters" << endl;
				}
				else if (i == 0 && Q3)
				{
					for (int i = 0; i < 2 * R; i++)
					{
						lista[i] = saved_list[i];
						set[i].used = used_flags[i];
					}
					i = 3 * R / 2;
					cout << "Loaded three quarters" << endl;
				}
				int los = rand() % (2 * R);										//draw a random number
				if (i == 0)												//just assigning word to the list and changing used flags of the same word but with different form and ordinal it will be used all the time when adding new word to generated list
				{
					if (los < 72)
					{
						set[los].used = 4;
						set[los + R / 2].used = 1;
						set[los + R].used = 2;
						set[los + 3 * R / 2].used = 1;
						lista[i] = set[los];
					}
					else if (los < 144)
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los + R / 2].used = 1;
						set[los + R].used = 2;
						lista[i] = set[los];
					}
					else if (los < 216)
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los + R / 2].used = 1;
						set[los - R].used = 2;
						lista[i] = set[los];
					}
					else
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los - R].used = 2;
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
						set[los + R].used = 2;
						set[los + 3 * R / 2].used = 1;
						lista[i] = set[los];
					}
					else if (los < 144)
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los + R / 2].used = 1;
						set[los + R].used = 2;
						lista[i] = set[los];
					}
					else if (los < 216)
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los + R / 2].used = 1;
						set[los - R].used = 2;
						lista[i] = set[los];
					}
					else
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los - R].used = 2;
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
						set[los + R].used = 2;
						set[los + 3 * R / 2].used = 1;
						lista[i] = set[los];
					}
					else if (los < 144)
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los + R / 2].used = 1;
						set[los + R].used = 2;
						lista[i] = set[los];
					}
					else if (los < 216)
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los + R / 2].used = 1;
						set[los - R].used = 2;
						lista[i] = set[los];
					}
					else
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los - R].used = 2;
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
						set[los + R].used = 2;
						set[los + 3 * R / 2].used = 1;
						lista[i] = set[los];
					}
					else if (los < 144)
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los + R / 2].used = 1;
						set[los + R].used = 2;
						lista[i] = set[los];
					}
					else if (los < 216)
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los + R / 2].used = 1;
						set[los - R].used = 2;
						lista[i] = set[los];
					}
					else
					{
						set[los].used = 4;
						set[los - R / 2].used = 1;
						set[los - R].used = 2;
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
					if (!Q1)
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
						cout << "Saving progress" << endl;
						for (int j = 0; j < 2 * R; j++)
						{
							saved_list[j] = lista[j];
							used_flags[j] = set[j].used;
						}
						Q1 = true;
					}
					if (set[los].used > 1)
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
						if (set[los + R / 2].used == 1) set[los + R / 2].used = 2;
						if (set[los + R].used == 1) set[los + R].used = 2;
						if (set[los + 3 * R / 2].used == 1) set[los + 3 * R / 2].used = 2;
						lista[i] = set[los];
					}
					else if (los < 144)
					{
						set[los].used = 4;
						if (set[los + R / 2].used == 1) set[los + R / 2].used = 2;
						if (set[los + R].used == 1) set[los + R].used = 2;
						if (set[los - R / 2].used == 1) set[los - R / 2].used = 2;
						lista[i] = set[los];
					}
					else if (los < 216)
					{
						set[los].used = 4;
						if (set[los + R / 2].used == 1) set[los + R / 2].used = 2;
						if (set[los - R].used == 1) set[los - R].used = 2;
						if (set[los - R / 2].used == 1) set[los - R / 2].used = 2;
						lista[i] = set[los];
					}
					else
					{
						set[los].used = 4;
						if (set[los - R / 2].used == 1) set[los - R / 2].used = 2;
						if (set[los - R].used == 1) set[los - R].used = 2;
						if (set[los - 3 * R / 2].used == 1) set[los - 3 * R / 2].used = 2;
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
					if (!Q2)
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
						cout << "Saving progress" << endl;
						for (int j = 0; j < 2 * R; j++)
						{
							saved_list[j] = lista[j];
							used_flags[j] = set[j].used;
						}
						Q1 = false;
						Q2 = true;
					}
					if (set[los].used > 2)
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
						if (set[los + R / 2].used == 2) set[los + R / 2].used = 3;
						if (set[los + R].used == 2) set[los + R].used = 3;
						if (set[los + 3 * R / 2].used == 2) set[los + 3 * R / 2].used = 3;
						lista[i] = set[los];
					}
					else if (los < 144)
					{
						set[los].used = 4;
						if (set[los + R / 2].used == 2) set[los + R / 2].used = 3;
						if (set[los + R].used == 2) set[los + R].used = 3;
						if (set[los - R / 2].used == 2) set[los - R / 2].used = 3;
						lista[i] = set[los];
					}
					else if (los < 216)
					{
						set[los].used = 4;
						if (set[los + R / 2].used == 2) set[los + R / 2].used = 3;
						if (set[los - R].used == 2) set[los - R].used = 3;
						if (set[los - R / 2].used == 2) set[los - R / 2].used = 3;
						lista[i] = set[los];
					}
					else
					{
						set[los].used = 4;
						if (set[los - R / 2].used == 2) set[los - R / 2].used = 3;
						if (set[los - R].used == 2) set[los - R].used = 3;
						if (set[los - 3 * R / 2].used == 2) set[los - 3 * R / 2].used = 3;
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
					if (!Q3)
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
						cout << "Saving progress" << endl;
						for (int j = 0; j < 2 * R; j++)
						{
							saved_list[j] = lista[j];
							used_flags[j] = set[j].used;
						}
						Q2 = false;
						Q3 = true;
					}
					if (set[los].used > 3)
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
		if (lista[2 * R - 1].used)										//if the last word is drawn, break the loop the list is set
		{
			do_list = false;
			cout << "Draw finished successfully. List is set" << endl;
			for (int i = 0; i < 2 * R; i++)
			{
				listaA[i] = lista[i];
			}
		}
		else
		{
			for (int i = 0; i < 2 * R; i++)
			{
				if (set[i].used)									//reset the used flag
				{
					set[i].used = 0;
				}
			}
			delete[]lista;
		}
	}
	cout << "Word   |   Distractor   |   Category   |   Type   |   Ordinal" << endl << endl << endl;
	wypisz_zbior(listaA, cout, 2 * R);
	fstream out;
	out.open("lists_noun_phrase.txt", ios::out);					//save the list to a file
	out << "Word   |   Distractor   |   Category   |   Type   |   Ordinal" << endl << endl << endl;
	wypisz_zbior(listaA, out, 2 * R);
	out.close();
	cout << "\nGenerating list for noun phrase task finished" << endl;
	return;
}

//For better chance to generate 2nd task might need to add checkpoints after each quarter and save used flags and drawn quarters somewhere and load them before each try

int main()
{
	bool program = true;
	while (program)
	{
		cout << "Pick which list would you like to generate: " << endl;
		cout << "1. Generate list for bare noun task" << endl;
		cout << "2. Generate list for noun phrase task" << endl;		//menu to choose which list to generate
		cout << "0. Exit" << endl;
		int choice;
		cin >> choice;
		switch (choice)													//switch to choose which list to generate
		{
		case 0:
			program = false;
			break;
		case 1:
			Bare_noun_list();
			break;
		case 2:
			noun_phrase_list();
			break;
		default:
			cout << "Wrong choice. Try again." << endl;
			break;
		}
	}
	return 0;
}