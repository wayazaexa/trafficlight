## Wokwi projekt
https://wokwi.com/projects/455485243193515009

### Ladda upp på wokwi
* Klicka i kodrutan på vänster sida.
* Tryck på 'F1'
* Skriv in 'upl' -> klicka på 'Upload Firmware and Start Simulation'


## En annorlunda lösning
För en annorlunda lösning kan ni kolla in bitshift-grenen.
Viktigt att notera är att detta *INTE* är ett rekommenderat sätt att koda för produktion,
då vi kommer förstöra logiken för alla andra pins i PORTB!! Men det kan vara kul att se
att det fungerar. Så länge vi vet att inga andra pins i PORTB används kan vi alltså använda
oss av rena bitshifts för att *samtidigt* släcka en LED och tända en annan.
