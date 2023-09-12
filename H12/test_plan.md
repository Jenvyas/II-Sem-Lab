# Jevgenijs Pigožņa, jp22034

## H12

Izveidot programmu valodā C++.  Ja programma darbojas ar failu, nedrīkst dublēt visa faila saturu operatīvajā atmiņā.
Ar faila komponenti tiek saprasts fiksēta garuma ieraksts. Sīkākās prasības sk. Laboratorijas darbu noteikumos.

>H12. Uzrakstīt programmu, kas ļauj izveidot un labot bināru failu, kura glabājas datumi, un kura ieraksta struktūra ir sekojoša: gads (int), mēnesis (int), diena (int), ieraksta statuss (0 vai 1). Programmai katrs jauns ieraksts jāieliek faila beigās. Ja failā tāds datums jau eksistē, tas nav jāpieliek. Jāparedz iespēja (1) izmest faila komponenti (loģiski atzīmējot kā izmestu), (2) izdrukāt failā esošos datumus uz ekrāna, (3) izmest loģiski izmestas komponentes fiziski.

empty file ->   add_date(2003,1,16)     -> 2003,1,16

empty file ->   add_date(2003,1,16)     -> 2003,1,16 removed
                remove_date(2003,1,16)

empty file ->   add_date(2003,1,16)     -> 2003,1,16
                add_date(192,1,2)          192,1,2 removed
                add_date(2005,3,5)         2005,3,5
                remove_date(192,1,2)

empty file ->   add_date(2003,1,16)     -> 2003,1,16
                add_date(192,1,2)          2005,3,5
                add_date(2005,3,5)         
                remove_date(192,1,2)
                delete_removed_dates()

empty file ->   add_date(2003,1,16)     -> 2003,1,16
                add_date(192,1,2)          2005,3,5
                add_date(2005,3,5)         2023,4,8
                add_date(2009,12,1)
                add_date(2023,4,18)        
                remove_date(192,1,2)
                remove_date(2009,12,1)
                delete_removed_dates()