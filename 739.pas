const khusus:array[1..8] of char=('A','E','I','O','U','Y','W','H');

var x,y:longint;
	masuk,encode:string;
	lewat:boolean;
	
function code(c:char):char;
	var x:longint;
	
	begin
		for x:=1 to 8 do if c=khusus[x] then
		begin
			code:='7';
			exit;
		end else
		
		case c of
		'B','P','F','V' : code:='1';
		'C','S','K','G','J','Q','X','Z' : code:='2';
		'D','T' : code:='3';
		'L' : code:='4';
		'M','N' : code:='5';
		'R' : code:='6';
		end;
	end;
	
begin
	writeln('         NAME                     SOUNDEX CODE');
	while not(eof) do
	begin
		readln(masuk);
		encode:=masuk[1];
		for x:=2 to length(masuk) do
		begin
			lewat:=FALSE;
			for y:=1 to 8 do if masuk[x]=khusus[y] then
			begin
				lewat:=TRUE;
				break;
			end;
			
			if not(lewat) then
				if((code(masuk[x])<>code(masuk[x-1]))and(length(encode)<4)) then encode:=encode+code(masuk[x]);
		end;
		if length(encode)<4 then for x:=1 to 4-length(encode) do encode:=encode+'0';
		
		write('         ',masuk);
		for x:=24 downto length(masuk) do write(' ');
		writeln(encode);
	end;
	writeln('                   END OF OUTPUT');
end.