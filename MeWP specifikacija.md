MeWP, oz. MeoW Protocol je protokol, ki ga od jutri ob 
dveh popoldne uporabljamo za komunikacijo med Raspberry 
Pi skatlo z user interfacom in Arduinom. Gre pa nekako tkole:
Od arduina na Pi
- informacije prehajajo kot:
  - paketki po 8 B
  - debug sporocila

sporocila se preprosto pretakajo po serialu. 
ne smejo vsebovati kaksnih cudnih neprintabilnih znakov, 
natancneje katerih se mi zdajle ne da pisat (imam dober razlog)
paketki so pa takile:
na arduinu so implementirani kot 64 bitni integerji. vsak bit posebi 
(razen najvecjih nekaj bitov) signalizira en error (to pomeni, da imamo prostora za 64 errorjev).
