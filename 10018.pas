var n,x,y,count:longint;
	temp:string;
	semen:char;
	bil1,bil2:longword;
	palin:boolean;
	
begin
	readln(n);
	for x:=1 to n do
	begin
		readln(bil1);
		count:=0;
		
		repeat
			inc(count);
			str(bil1,temp);
			for y:=1 to length(temp) div 2 do
			begin
				semen:=temp[y];
				temp[y]:=temp[length(temp)-y+1];
				temp[length(temp)-y+1]:=semen;
			end;
			val(temp,bil2,y);
			bil1:=bil1+bil2;
			
			palin:=TRUE;
			str(bil1,temp);
			for y:=1 to length(temp) div 2 do 
				if temp[y]<> temp[length(temp)-y+1] then
				begin
					palin:=FALSE;
					break;
				end;
		until palin;
		
		writeln(count,' ',bil1);
	end;
end.