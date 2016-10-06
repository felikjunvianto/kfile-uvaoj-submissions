var n:ansistring;
	x:longint;
	
function downcase(x:char):char;
	begin
		if ((ord(x)>=65)and(ord(x)<=90)) then x:=chr(ord(x)-ord('A')+ord('a'));
		downcase:=x;
	end;
	
begin
	readln(n);
	for x:=1 to length(n) do
	case downcase(n[x]) of
	'e' : write('q');
	'r' : write('w');
	't' : write('e');
	'y' : write('r');
	'u' : write('t');
	'i' : write('y');
	'o' : write('u');
	'p' : write('i');
	'[' : write('o');
	']' : write('p');
	'\' : write('[');
	'd' : write('a');
	'f' : write('s');
	'g' : write('d');
	'h' : write('f');
	'j' : write('g');
	'k' : write('h');
	'l' : write('j');
	';' : write('k');
	chr(39) : write('l');
	'c' : write('z');
	'v' : write('x');
	'b' : write('c');
	'n' : write('v');
	'm' : write('b');
	',' : write('n');
	'.' : write('m');
	'/' : write(',');
	else write(n[x]);
	end;
	writeln;
end.