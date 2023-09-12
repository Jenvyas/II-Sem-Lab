# Jevgenijs Pigožņa, jp22034

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

1) <> -> false
2) <1> -> false
3) <1,2> -> false
4) <6,6> -> true
5) <4,5,8,7,4> -> true
6) <3,27,27,4> -> true
7) <33,27,33,27> -> true
8) <3,26,27,4,2,887,2341,13,15> -> false
9) <3,26,13,4,2341,887,2341,13,15> -> true