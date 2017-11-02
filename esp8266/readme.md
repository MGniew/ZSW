PRZYGOTOWANIE

1. Przed rozpoczêciem pracy zainstaluj Arduino IDE (moja wersja 1.8.5), projekt by³ testowany na ESP8266 z ModeMCU v3 (uk³ad po³¹czeñ w osobnym pliku).
2. W zak³¹dce Plik->Preferecje, w polu "Dodatkowe adresy URP dla menad¿era p³ytak" plisujemy poni¿szy link:

http://arduino.esp8266.com/stable/package_esp8266com_index.json

3. Wchodzimy w Narzêdzia->P³ytka->Mened¿er p³ytek...
4. Wyszukujemy ESP8266 Comunity i instalujemy najnowsz¹ wersjê (u mnie 2.3.0)
5. Przed pierwszym uruchomieniem p³ytki zalecana jest aktualizacja firmware'u wed³ug instrukcji na stronie:

http://hobbyspace.pl/nodemcu-jak-wgrac-firmware/


WGRYWANIE PROJEKTU (Arduino IDE)

1. W menu Narzêdzia->P³ytki wybieramy 

NodeMCU 1.0(ESP-12E Module)

2. Opcje po³¹czenia powinny ustawic siê automatycznie prawid³owo, dla pewnoœci:

CPU Frequency: "80 MHz"
Flash Size: "4M (3M SPIFFS)"
Upload Speed: "115200"

3. W zak³adce Narzêdzia->Port wybieramy porn na którym podpieliœmy p³ytkê
4. Wybieramy opcjê Wgraj (lub strza³ka w prawo na górnym pasku)