var x,n,s,d:longint;
	score1,score2:longint;
	
begin
	readln(n);
	for x:=1 to n do
	begin
		readln(s,d);
		if(d>s) then writeln('impossible') else
		begin
			score1:=((s+d) div 2);
			score2:=((s-d) div 2);
			if((score1+score2<>s)or(score1-score2<>d)) then writeln('impossible') 
				else writeln(score1,' ',score2);
		end;
	end;
end.