<head>
<link rel="stylesheet" type="text/css" href="Exer2CSS_Tong.css">
</head>

<body>
<div class="a">
<img src="1.jpg" width=100px; height=100px>
	<div class="a1">
	Jane:Hello World.
	<br/>
	Like：<span id="countspan"></span>
	<br/>
	<button onclick="countNumber();">Like</button>
	<script type="text/javascript">//like count
		localStorage.clear();//start from 0 while refresh
		if(!localStorage.countAll){                                                                                          
			localStorage.countAll = 0;
		}
			document.getElementById('countspan').innerHTML = localStorage.countAll;
		function countNumber(){
			localStorage.countAll++;
			document.getElementById('countspan').innerHTML = localStorage.countAll;
		}	
	</script>
	<button id="bt1">Comment</button>
	</div>
</div>
<br/>
<script type="text/javascript">//comment display
	window.onload=function(){
	var obta=document.getElementById("bt1");
	var obtb=document.getElementById("bt2");
	var odivb=document.getElementById("b");
	var boxa=document.getElementById("b1");
	var boxb=document.getElementById("b2");
	obta.onclick=function disp1(){
		if(odivb.style.display=="none"){
			odivb.style.display="block";
			boxa.style.display="block";
			boxb.style.display="none";
		}
		else{
			odivb.style.display="none";
		}
	}
	obtb.onclick=function disp2(){
		if(boxb.style.display=="none"){
			boxb.style.display="block";
			boxa.style.display="none";
		}
		else
		{
			boxb.style.display="none";
			boxa.style.display="block";
		}
	}
}
</script>

<div id="b" style="display:none">
	<img src="2.jpg" width=100px; height=100px>
	
	<div id="b1" style="display:block">
		<form method="get"  id= "form" target="nm_iframe">
			<textarea name="comment" id="comment" cols="50" rows="6" onchange="getinput()"></textarea>
			<button id="bt2">Comment</button>
		</form>
	</div>
	<div id="b2" style="display:none">
		<iframe id="id_iframe" name="nm_iframe" style="display:none;"></iframe>
		<span id="disp"></span>
		<script type="text/javascript">//display comment
		function getinput(){
			var a = document.getElementById('comment').value;
			document.getElementById('disp').innerHTML = "Comment: "+a;
		}
		</script>
		<?php
			$com=$_GET['comment'];
			$file = fopen("commets.txt", "a+");
			fwrite($file, $com);
			echo "<br/>Date Posted: " . date("M-d-Y \, h:i:s a", time() + 7*3600);
			unset($com);
			unset($_GET['comment']);
			fclose($file);
		?>
	</div>
</div>
</body>