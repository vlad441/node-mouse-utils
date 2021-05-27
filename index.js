const procs = require("child_process"); let fpath = __dirname+"/mkutils.exe";

function cppexec(cmd)
{	return new Promise(function(resolve, reject){
		procs.execFile(fpath, cmd.split(" "), (error, stdout, stderr) => {
			//if(error){ console.log(`exec error: ${error.message}`); }
			if(stderr) { console.log(`stderr: ${stderr}`); }
			resolve(stdout); }); }); }

function mkfuncs()
{	let mkutils = {};
	mkutils.GetCursorPos = async function(){ let resp = await cppexec("-getpos"); resp=resp.split(" "); return {x: resp[1], y: resp[2]};  }
	mkutils.SetCursorPos = async function(x, y){ let resp = await cppexec("-setpos "+x+" "+y); if(resp.indexOf("error")<0){ return true; }else{ return false; } }
	mkutils.Click = async function(btn)
	{ let resp; if(btn=="right"){ resp = await cppexec("-rclick"); }else if(btn=="double"){ resp = await cppexec("-dclick"); }
		else{ resp = await cppexec("-click"); } if(resp.indexOf("error")<0){ return true; }else{ return false; } }
	mkutils.PressKey = async function(key){ let resp = await cppexec("-press "+key); if(resp.indexOf("error")<0){ return true; }else{ return false; } }
	return mkutils;
}

module.exports = mkfuncs();

