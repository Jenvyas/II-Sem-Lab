# Lab HW for Software dev Basics course

Komanda and pasts are two tasks that were a part of the data structures half of the course.

## F14

Izveidot programmu valodā C++, kas apstrādā teksta failu secīgā režīmā.
Dati no faila jānolasa pa vienai rindiņai. Nedrīkst dublēt visa faila saturu operatīvajā atmiņā.
Sīkākas prasības sk. Laboratorijas darbu noteikumos.

>F14. Dots teksta fails, kurā atrodas C++ programmas teksts. Pārbaudīt dotajā programmas tekstā atverošo un aizverošo iekavu lietojumu (t.i., vai katrai atverošajai iekavai seko aizverošā, un vai iekavu secība ir pieļaujama). Nepieļaujami ir sekojoši gadījumi:  )(   vai  ()) , vai  ((). Drīkst uzskatīt, ka programmas tekstā nav komentāru un ka attiecīgie simboli neparādīsies teksta literāļos.


## G9 

Izveidot divas programmas valodā C++, kas strādā ar vērtību virkni divos dažādos veidos:
  1) to realizējot kā vienvirziena saistīto sarakstu, izmantojot dinamiskas datu struktūras,
  2) izmantojot STL::list konteineru.
Abās realizācijās ir jāizveido prasītā specifiskā vērtību virknes apstrādes funkcija un jānodemonstrē tā darbībā,
cita starpā parādot gan sākotnējās, gan rezultējošās vērtības.
Abās programmās:  
  a) jābūt iespējai ievadīt saraksta elementus (izveidot patvaļīgu sarakstu),
  b) jāpielieto uzrakstītā funkcija sarakstam,  
  c) jāizdrukā saraksts pēc funkcijas darbības.  
  d) beigās jāiznīcina saraksts - korekti jāatbrīvo izdalītā atmiņa(lietojot delete vai clear).
Sīkākas prasības sk. Laboratorijas darbu noteikumos.

>G9. Uzrakstīt funkciju, kas pārbauda, vai sarakstā ir  vismaz divi elementi ar vienādām vērtībām.


## H12

Izveidot programmu valodā C++.  Ja programma darbojas ar failu, nedrīkst dublēt visa faila saturu operatīvajā atmiņā.
Ar faila komponenti tiek saprasts fiksēta garuma ieraksts. Sīkākās prasības sk. Laboratorijas darbu noteikumos.

>H12. Uzrakstīt programmu, kas ļauj izveidot un labot bināru failu, kura glabājas datumi, un kura ieraksta struktūra ir sekojoša: gads (int), mēnesis (int), diena (int), ieraksta statuss (0 vai 1). Programmai katrs jauns ieraksts jāieliek faila beigās. Ja failā tāds datums jau eksistē, tas nav jāpieliek. Jāparedz iespēja (1) izmest faila komponenti (loģiski atzīmējot kā izmestu), (2) izdrukāt failā esošos datumus uz ekrāna, (3) izmest loģiski izmestas komponentes fiziski.


## GG

GG – STL list un saistītais saraksts ar izņēmumsituāciju apstrādi un vienībtestēšanu**.

* atrisināt uzdevumu G divos veidos:
  a) izmantojot dinamiskas datu struktūras (saistīto sarakstu vtml.),
  b) izmantojot STL::list konteineru.

** tas pats uzdevums, kas G, bet tā risinājums (a) jāpapildina ar divām lietām:
  1) vismaz viena no datu pārbaudēm jārealizē, izmantojot izņēmumsituāciju apstrādes (exception handling) mehānismu,
  2) vismaz viena funkcija (vēlams, galvenā) ir jānotestē, izmantojot vienībtestēšanu, kur attiecīgā funkcija būtu jāpārbauda uz vismaz trīs dažādiem nosacījumiem;
     šim nolūkam, kā minimums, ir nepieciešams:
     (1) šo funkciju iznest ārā citā failā (nekā funkcija main),
     (2) izveidot otru projektu speciāli šīs funkcijās testēšanai (tātad, kopā būs divi projekti, parastais, kas izmantos funkciju, otrais, kas testēs).

Papildus norāde: šādam vienībtestēšanas projektam daļēji atbilst iepriekšējā semestra pēdējais laboratorijas darbs (ar klasēm) ar cieti iekodētu main funkciju.