var frame,album,numPhotos,images,fader,img,oldimg,w,h,ow,oh,loop,
    busy=false,y=z=1;i=0,r=false,t="none",dur=0;
document.addEventListener("keydown", function(k){action(k.which);});
function init(){
  frame=canvas.getContext("2d");
  album=JSON.parse('['+
    '{ "url":"01.jpg", "txt":"First Hike"    },'+
    '{ "url":"02.jpg", "txt":"Bike Park"     },'+
    '{ "url":"03.jpg", "txt":"Egg Hunt"      },'+
    '{ "url":"04.jpg", "txt":"Snack Time"    },'+
    '{ "url":"05.jpg", "txt":"Ice Cream"     },'+
    '{ "url":"06.jpg", "txt":"Spidey Web"    },'+
    '{ "url":"07.jpg", "txt":"Sunshine"      },'+
    '{ "url":"08.jpg", "txt":"Bike Race"     },'+
    '{ "url":"09.jpg", "txt":"Rainbow"       },'+
    '{ "url":"10.jpg", "txt":"Chasing Waves" },'+
    '{ "url":"11.jpg", "txt":"Tight Fit"     },'+
    '{ "url":"12.jpg", "txt":"Runaway"       },'+
    '{ "url":"13.jpg", "txt":"Gurdwara"      },'+
    '{ "url":"14.jpg", "txt":"Mixing"        },'+
    '{ "url":"15.jpg", "txt":"Smiles"        },'+
    '{ "url":"16.jpg", "txt":"Pumpkin Patch" },'+
    '{ "url":"17.jpg", "txt":"Sprinkle Donut"},'+
    '{ "url":"18.jpg", "txt":"Christmas"     },'+
    '{ "url":"19.jpg", "txt":"For You"       },'+
    '{ "url":"20.jpg", "txt":"Strike a Pose" }]');
  numPhotos=album.length;
  images=new Array(numPhotos);
  for(var n=0;n<numPhotos;n++){
    images[n]=new Image();
    images[n].src="resources/img/"+album[n].url;}
  window.setTimeout(draw,25);
}
function action(x){
  var b=document.getElementById("j_idt11:b"),
    s=document.getElementById("j_idt11:s"),
    p=document.getElementById("j_idt11:p"),
    n=document.getElementById("j_idt11:n"),
    rand=document.getElementById("j_idt11:rand");
  if(x=="slide"||x=="dslv"||x=="fade"||x=="none") dur=(x=="none"?0:1),t=x;
  else if((x=="next"||x==39)&&!busy){ if(r)i=Math.floor(Math.random()*numPhotos);
                                      else if(++i>=numPhotos)i=0;
                                      draw(1);}
  else if((x=="back"||x==37)&&!busy){ if(--i<0)i=numPhotos-1;
                                      draw(0);}
  else if(x=="play"){ p.disabled=true,s.disabled=false;
                      loop=setInterval(action,2000,"next");}
  else if(x=="stop"){ s.disabled=true,p.disabled=false;
                      clearInterval(loop);}
  else if(x=="rand"){ if(r)rand.innerHTML="⤮",n.disabled=b.disabled=r=false;
                      else rand.innerHTML="⇉",n.disabled=b.disabled=r=true;}
}
function draw(d){
// remove old photo
  busy=true;
  if(t=="slide"){
    oldimg=img,ow=w,oh=h;
    var slideout=setInterval(function(){
        frame.fillRect(0,0,800,600);
        frame.drawImage(oldimg,(ow<oh?175:0)-(d?z:-z)*20,0,ow,oh);
        if(++z>40)clearInterval(slideout),z=1;
      },dur*25);
  }else if(t=="dslv"){
    frame.drawImage(img,w<h?175:0,0,w,h);
  }else if(t=="fade"){
    frame.drawImage(img,w<h?175:0,0,w,h);
    var fadeout=setInterval(function(){
        frame.globalAlpha=z/10;
        frame.fillRect(0,0,800,600);
        if(++z>10)clearInterval(fadeout),z=1;
      },dur*50);
  }
// add new photo
  if(t=="slide"){
    var slidein=setInterval(function(){
      img=images[i];
      w=img.width;
      h=img.height;
      frame.drawImage(img,(w<h?175:0)+(d?800-y*20:y*20-800),0,w,h);
      if(++y>40)clearInterval(slidein),y=1,busy=false;
    },dur*25);
  }else setTimeout(function(){
    var fadein=setInterval(function(){
      img=images[i],w=img.width,h=img.height;
      frame.globalAlpha=y/(t=="dslv"?20:10);
      frame.fillRect(0,0,800,600);
      frame.drawImage(img,w<h?175:0,0,w,h);
      if(++y>(t=="dslv"?20:10))clearInterval(fadein),y=1,busy=false;
    },dur*50);
  },dur*(t=="fade"?500:0));
// update caption
  setTimeout(function(){
    title.innerHTML=album[i].txt;
  },dur*500);
}