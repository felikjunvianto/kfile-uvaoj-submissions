var x:longint;
	masuk:ansistring;
	
begin
	while not(eof) do
	begin
		readln(masuk);
		for x:=1 to length(masuk) do
			case masuk[x] of
			'W':write('Q');
			'E':write('W');
			'R':write('E');
			'T':write('R');
			'Y':write('T');
			'U':write('Y');
			'I':write('U');
			'O':write('I');
			'P':write('O');
			'[':write('P');
			']':write('[');
			'\':write(']');
			
			'S':write('A');
			'D':write('S');
			'F':write('D');
			'G':write('F');
			'H':write('G');
			'J':write('H');
			'K':write('J');
			'L':write('K');
			';':write('L');
			chr(39):write(';');
			
			'X':write('Z');
			'C':write('X');
			'V':write('C');
			'B':write('V');
			'N':write('B');
			'M':write('N');
			',':write('M');
			'.':write(',');
			'/':write('.');
			
			'2':write('1');
			'3':write('2');
			'4':write('3');
			'5':write('4');
			'6':write('5');
			'7':write('6');
			'8':write('7');
			'9':write('8');
			'0':write('9');
			'-':write('0');
			'=':write('-');
			else write(masuk[x]);
			end;
		writeln;
	end;
end.
