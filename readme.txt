//Tester avec : ./a.exe " Test char %-+0c et int %0 +-5.7d" "x" "42"
//Modifier le main (pas de atoi mais envoyez un char à la place)
//Variable utiles :
//p.format (char*) contient la chaine de charactere entiere passé par l'utilisateur 
//p.conv (char*) contient les éventuels flags se trouvant entre le '%' et le 'c'
//p.i (int) c'est la position du % dans p.format
//p.diff (int) c'est la position du dernier flags dans p.conv, si p.diff est égal à 0 il n'y à pas de flags
//printf ("Chaine de charactere : %s | chaine de flags : %s\n", p.format, p.conv);
//printf ("Position du %% dans la chaine de charactere : %c | position du dernier charactere avant le c %c | p.diff : %d\n", p.format[p.i], p.conv[p.diff - 1], p.diff);
