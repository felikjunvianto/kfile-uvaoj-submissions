var x,n:longint;
	jolly,tes:array[1..3000] of longint;
	valid:boolean;
	
begin
	while not(eof) do
	begin
		fillchar(jolly,sizeof(jolly),0);
		fillchar(tes,sizeof(tes),0);
		read(n);
		for x:=1 to n do read(jolly[x]);
		readln;
		for x:=1 to n-1 do inc(tes[abs(jolly[x]-jolly[x+1])]);
		valid:=TRUE;
		for x:=1 to n-1 do if tes[x]=0 then
		begin
			valid:=FALSE;
			break;
		end;
		if valid then writeln('Jolly') else writeln('Not jolly');
	end;
end.