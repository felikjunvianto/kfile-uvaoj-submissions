var x,y,z,time:longint;
	waktu_awal,waktu_akhir:real;
	speed,distance,temp:real;
	command:string;
	
begin
	distance:=0;
	waktu_awal:=0;
	speed:=0;
	
	while not(eof) do
	begin
		readln(command);
		val(copy(command,1,2),time,y);
		waktu_akhir:=time*3600;
		val(copy(command,4,2),time,y);
		waktu_akhir:=waktu_akhir+time*60;
		val(copy(command,7,2),time,y);
		waktu_akhir:=waktu_akhir+time;
		
		z:=pos(' ',command);
		case z of
		9 :	begin
				distance:=distance+(waktu_akhir-waktu_awal)/3600*speed;
				val(copy(command,z+1,length(command)-z),x,y);
				speed:=x;
				waktu_awal:=waktu_akhir;
			end;
			
		0 : begin
				temp:=((waktu_akhir-waktu_awal)*speed/3600)+distance;
				writeln(command,' ',temp:0:2,' km');
			end;
		end;
	end;
end.