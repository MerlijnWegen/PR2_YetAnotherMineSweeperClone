
```
Yet another:
 __  __ _____ _   _ ______  _______          ________ ______ _____  ______ _____          
|  \/  |_   _| \ | |  ____|/ ____\ \        / /  ____|  ____|  __ \|  ____|  __ \   
| \  / | | | |  \| | |__  | (___  \ \  /\  / /| |__  | |__  | |__) | |__  | |__) |   
| |\/| | | | | . ` |  __|  \___ \  \ \/  \/ / |  __| |  __| |  ___/|  __| |  _  /   
| |  | |_| |_| |\  | |____ ____) |  \  /\  /  | |____| |____| |    | |____| | \ \    
|_|  |_|_____|_| \_|______|_____/    \/  \/   |______|______|_|    |______|_|  \_\     
clone.
```
TODO:
- Gamelogic
- Proper Screen for adjusting variables (adjustvariable)
- Pre-game Difficuly select screen
- layout for gameplay



Out of scope changes: (won't be happing but future reference)
- Improved implementation for grid_t.
- 


To Discuss:
- SDL2 or Commandline?
- TaakVerdeling

### limitatie Email:
---
Je ontwerp is goedgekeurd en je kunt nu beginnen met de implementatie, geweldig! Houd rekening met de volgende belangrijke informatie voordat je begint met coderen:

Houd je aan het ontwerp - Het is cruciaal dat je je strikt houdt aan het goedgekeurde ontwerp. Kleine aanpassingen voor technische haalbaarheid zijn toegestaan, maar grote wijzigingen zijn niet toegestaan.

Voorbeelden van kleine aanpassingen zijn:
-De namen van functies of variabelen (of structure members) wijzigen
-Parameters aan functies toevoegen/verwijderen
-Hulpfuncties toevoegen die niet in het ontwerp stonden
-Enumeraties toevoegen
-Eenvoudige members (een boolean, int, enz.) aan structures toevoegen

Het wijzigen van de algemene architectuur van het ontwerp is niet toegestaan. Dat wil zeggen: het toevoegen van nieuwe structures die niet in het ontwerp stonden, of het wijzigen van de relaties tussen structures (stel bijvoorbeeld dat een game structure een pointer naar een board structure bevat; je mag die pointer niet verwijderen en in plaats daarvan een pointer van de board structure naar de game structure toevoegen).

Een logboek bijhouden - Welke (kleine) wijziging je ook aanbrengt, je moet een logboek (een changelog) bijhouden van deze wijzigingen in een (tekst- of markdown-)bestand. In dit bestand moet je elke wijziging die je aanbrengt in het ontwerp documenteren, samen met een korte uitleg waarom je die wijziging hebt aangebracht.

Gebruik ditzelfde document ook om bij te houden wie aan welk deel van de code heeft gewerkt.

Aan het einde van het project moet je dit changelog samen met je code indienen.

