PRZYGOTOWANIE

1. Przed rozpocz�ciem pracy zainstaluj Arduino IDE (moja wersja 1.8.5), projekt by� testowany na ESP8266 z ModeMCU v3 (uk�ad po��cze� w osobnym pliku).
2. W zak��dce Plik->Preferecje, w polu "Dodatkowe adresy URP dla menad�era p�ytak" plisujemy poni�szy link:

http://arduino.esp8266.com/stable/package_esp8266com_index.json

3. Wchodzimy w Narz�dzia->P�ytka->Mened�er p�ytek...
4. Wyszukujemy ESP8266 Comunity i instalujemy najnowsz� wersj� (u mnie 2.3.0)
5. Przed pierwszym uruchomieniem p�ytki zalecana jest aktualizacja firmware'u wed�ug instrukcji na stronie:

http://hobbyspace.pl/nodemcu-jak-wgrac-firmware/


WGRYWANIE PROJEKTU (Arduino IDE)

1. W menu Narz�dzia->P�ytki wybieramy 

NodeMCU 1.0(ESP-12E Module)

2. Opcje po��czenia powinny ustawic si� automatycznie prawid�owo, dla pewno�ci:

CPU Frequency: "80 MHz"
Flash Size: "4M (3M SPIFFS)"
Upload Speed: "115200"

3. W zak�adce Narz�dzia->Port wybieramy porn na kt�rym podpieli�my p�ytk�
4. Wybieramy opcj� Wgraj (lub strza�ka w prawo na g�rnym pasku)