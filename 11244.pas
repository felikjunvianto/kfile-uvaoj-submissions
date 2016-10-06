type koordinat=record
	 x,y:longint;
	 end;
	 
var x,y,counter,a,b,n,m:longint;
	sky:array[1..110,1..110] of char;
	queue:array[1..12100] of koordinat;
	bintang:boolean;
	
begin
	repeat
		readln(a,b);
		if(a<>0) and (b<>0) then
		begin
			fillchar(sky,sizeof(sky),'.');
			for y:=1 to a do
			begin
				for x:=1 to b-1 do read(sky[x,y]);
				readln(sky[b,y]);
			end;
			n:=0;
			counter:=0;
			for y:=1 to a do
				for x:=1 to b do if sky[x,y]='*' then  
				begin
					inc(n);
					queue[n].x:=x;
					queue[n].y:=y;
				end;
				
			for m:=1 to n do
			begin
				bintang:=TRUE;
				for x:=-1 to 1 do
					for y:=-1 to 1 do if ((x<>0)or(y<>0)) then
						if sky[queue[m].x+x,queue[m].y+y]='*' then bintang:=FALSE;
				if bintang then inc(counter);
			end;
			writeln(counter);
		end;
	until((a=0)and(b=0));
end.