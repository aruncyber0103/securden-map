<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>PAM & Securden — Complete Concept Map</title>
<style>
@import url('https://fonts.googleapis.com/css2?family=Space+Grotesk:wght@300;400;500;600;700&family=JetBrains+Mono:wght@400;700&display=swap');

*,*::before,*::after{box-sizing:border-box;margin:0;padding:0;}
:root{
  --bg:#060810;
  --surface:#0d0f1a;
  --border:#1a1d30;
  --text:#dde4ff;
  --muted:#5a6090;
  --c0:#00d4ff;   /* PAM core */
  --c1:#ff4d8f;   /* Securden */
  --c2:#7c6aff;   /* Products */
  --c3:#00e5a0;   /* How it works */
  --c4:#ffaa00;   /* Threats */
  --c5:#ff6b35;   /* Compliance */
  --c6:#a78bfa;   /* Features */
}
body{background:var(--bg);color:var(--text);font-family:'Space Grotesk',sans-serif;overflow:hidden;height:100vh;width:100vw;user-select:none;}

/* Noise overlay */
body::after{content:'';position:fixed;inset:0;background-image:url("data:image/svg+xml,%3Csvg viewBox='0 0 256 256' xmlns='http://www.w3.org/2000/svg'%3E%3Cfilter id='noise'%3E%3CfeTurbulence type='fractalNoise' baseFrequency='0.9' numOctaves='4' stitchTiles='stitch'/%3E%3C/filter%3E%3Crect width='100%25' height='100%25' filter='url(%23noise)' opacity='0.035'/%3E%3C/svg%3E");pointer-events:none;z-index:0;opacity:.5;}

/* Grid */
body::before{content:'';position:fixed;inset:0;background-image:linear-gradient(rgba(0,212,255,0.03) 1px,transparent 1px),linear-gradient(90deg,rgba(0,212,255,0.03) 1px,transparent 1px);background-size:56px 56px;pointer-events:none;z-index:0;}

canvas{position:fixed;inset:0;z-index:1;cursor:grab;}
canvas:active{cursor:grabbing;}

/* ── TOP BAR ── */
#topbar{
  position:fixed;top:0;left:0;right:0;z-index:100;
  padding:14px 24px;
  display:flex;align-items:center;justify-content:space-between;
  background:linear-gradient(to bottom,rgba(6,8,16,.97) 60%,transparent);
  border-bottom:1px solid rgba(255,255,255,0.04);
}
.brand{display:flex;align-items:center;gap:12px;}
.brand-dot{width:10px;height:10px;border-radius:50%;background:var(--c0);box-shadow:0 0 12px var(--c0);animation:blink 2s ease-in-out infinite;}
@keyframes blink{0%,100%{opacity:1;}50%{opacity:.4;}}
.brand-title{font-size:.85rem;font-weight:700;letter-spacing:.12em;text-transform:uppercase;color:var(--c0);}
.brand-sub{font-size:.65rem;font-family:'JetBrains Mono',monospace;color:var(--muted);margin-top:1px;}
#hint{font-size:.65rem;font-family:'JetBrains Mono',monospace;color:var(--muted);letter-spacing:.07em;animation:fadepulse 3s ease-in-out infinite;}
@keyframes fadepulse{0%,100%{opacity:.35;}50%{opacity:.9;}}

/* ── LEGEND ── */
#legend{
  position:fixed;top:70px;left:20px;z-index:100;
  background:rgba(13,15,26,.88);border:1px solid var(--border);border-radius:12px;
  padding:14px 16px;backdrop-filter:blur(16px);
  display:flex;flex-direction:column;gap:8px;
}
.leg-item{display:flex;align-items:center;gap:8px;font-size:.65rem;font-family:'JetBrains Mono',monospace;color:var(--muted);cursor:pointer;transition:color .2s;}
.leg-item:hover{color:var(--text);}
.leg-dot{width:10px;height:10px;border-radius:50%;flex-shrink:0;}

/* ── INFO PANEL ── */
#panel{
  position:fixed;right:20px;top:50%;transform:translateY(-50%);
  width:300px;
  background:rgba(13,15,26,.94);border:1px solid var(--border);border-radius:16px;
  padding:0;z-index:200;backdrop-filter:blur(24px);
  opacity:0;pointer-events:none;transition:opacity .25s,transform .25s;
  box-shadow:0 0 80px rgba(0,0,0,.6);overflow:hidden;
}
#panel.open{opacity:1;pointer-events:all;}
#panel-header{padding:20px 20px 16px;border-bottom:1px solid var(--border);}
#panel-tag{font-size:.58rem;font-family:'JetBrains Mono',monospace;letter-spacing:.1em;text-transform:uppercase;margin-bottom:8px;}
#panel-title{font-size:1.15rem;font-weight:700;line-height:1.25;}
#panel-close{position:absolute;top:14px;right:14px;background:none;border:1px solid var(--border);color:var(--muted);width:24px;height:24px;border-radius:6px;cursor:pointer;font-size:.75rem;display:flex;align-items:center;justify-content:center;transition:all .2s;}
#panel-close:hover{color:var(--text);border-color:rgba(255,255,255,.3);}
#panel-body{padding:16px 20px;}
#panel-desc{font-size:.78rem;color:#9ba8d0;line-height:1.65;margin-bottom:14px;}
#panel-chips{display:flex;flex-wrap:wrap;gap:6px;}
.chip{font-size:.6rem;font-family:'JetBrains Mono',monospace;padding:4px 10px;border-radius:20px;border:1px solid;letter-spacing:.05em;}

/* ── CONTROLS ── */
#controls{
  position:fixed;bottom:20px;left:50%;transform:translateX(-50%);
  z-index:200;display:flex;gap:8px;
}
.btn{
  background:rgba(13,15,26,.9);border:1px solid var(--border);color:var(--muted);
  padding:8px 16px;border-radius:8px;cursor:pointer;
  font-family:'JetBrains Mono',monospace;font-size:.65rem;letter-spacing:.08em;
  transition:all .2s;backdrop-filter:blur(10px);
}
.btn:hover{color:var(--text);border-color:rgba(0,212,255,.5);box-shadow:0 0 16px rgba(0,212,255,.15);}

/* ── SEARCH ── */
#search-wrap{position:fixed;bottom:20px;right:20px;z-index:200;}
#search{
  background:rgba(13,15,26,.9);border:1px solid var(--border);color:var(--text);
  padding:8px 14px;border-radius:8px;
  font-family:'JetBrains Mono',monospace;font-size:.65rem;letter-spacing:.05em;
  width:180px;outline:none;transition:all .2s;backdrop-filter:blur(10px);
}
#search::placeholder{color:var(--muted);}
#search:focus{border-color:rgba(0,212,255,.5);box-shadow:0 0 16px rgba(0,212,255,.1);}
</style>
</head>
<body>

<div id="topbar">
  <div class="brand">
    <div class="brand-dot"></div>
    <div>
      <div class="brand-title">PAM & Securden</div>
      <div class="brand-sub">Complete Concept Map · click nodes · drag · scroll to zoom</div>
    </div>
  </div>
  <div id="hint">← Click any node to learn more →</div>
</div>

<div id="legend">
  <div class="leg-item" data-group="core"><div class="leg-dot" style="background:#00d4ff;box-shadow:0 0 6px #00d4ff44;"></div>Core PAM</div>
  <div class="leg-item" data-group="securden"><div class="leg-dot" style="background:#ff4d8f;box-shadow:0 0 6px #ff4d8f44;"></div>Securden</div>
  <div class="leg-item" data-group="product"><div class="leg-dot" style="background:#7c6aff;box-shadow:0 0 6px #7c6aff44;"></div>Products</div>
  <div class="leg-item" data-group="feature"><div class="leg-dot" style="background:#a78bfa;box-shadow:0 0 6px #a78bfa44;"></div>Key Features</div>
  <div class="leg-item" data-group="threat"><div class="leg-dot" style="background:#ffaa00;box-shadow:0 0 6px #ffaa0044;"></div>Threats PAM Stops</div>
  <div class="leg-item" data-group="compliance"><div class="leg-dot" style="background:#ff6b35;box-shadow:0 0 6px #ff6b3544;"></div>Compliance</div>
</div>

<canvas id="c"></canvas>

<div id="panel">
  <div id="panel-header">
    <div id="panel-tag"></div>
    <div id="panel-title"></div>
    <button id="panel-close">✕</button>
  </div>
  <div id="panel-body">
    <div id="panel-desc"></div>
    <div id="panel-chips"></div>
  </div>
</div>

<div id="controls">
  <button class="btn" id="btn-reset">⟳ Reset</button>
  <button class="btn" id="btn-fit">⊞ Fit All</button>
  <button class="btn" id="btn-anim" title="Toggle animation">◉ Animate</button>
</div>

<div id="search-wrap">
  <input id="search" type="text" placeholder="🔍 search nodes...">
</div>

<script>
// ═══════════════════════════════════════════════════════
//  DATA
// ═══════════════════════════════════════════════════════
const G={core:'Core PAM',securden:'Securden',product:'Product',feature:'Feature',threat:'Threat PAM Stops',compliance:'Compliance'};
const COLOR={core:'#00d4ff',securden:'#ff4d8f',product:'#7c6aff',feature:'#a78bfa',threat:'#ffaa00',compliance:'#ff6b35'};

const nodes=[
  // ── CORE ──
  {id:'pam',       group:'core',    x:0,   y:0,   r:72, label:'PAM',
   sub:'Privileged Access\nManagement',
   desc:'Privileged Access Management (PAM) is a cybersecurity discipline that controls, monitors, and audits all access to critical systems by privileged users — admins, root accounts, service accounts, and more. It\'s often called the "keys to the kingdom" because whoever holds these accounts can access everything. PAM is the framework companies use to ensure only the right people get the right access at the right time.',
   chips:['Identity Security','Zero Trust','Least Privilege','Audit Trails']},

  {id:'privileged',group:'core',    x:-320,y:-140, r:46, label:'Privileged\nAccounts',
   desc:'Accounts with elevated permissions beyond normal users — sysadmins, domain admins, root users, service accounts, SSH keys, DevOps secrets. These are high-value targets because compromising even one can give an attacker total control over an organization\'s infrastructure.',
   chips:['Admin Accounts','Service Accounts','Root Users','SSH Keys','Shared Accounts']},

  {id:'vault',     group:'core',    x:320, y:-140, r:46, label:'Encrypted\nVault',
   desc:'A hardened, encrypted repository where all privileged credentials, passwords, keys, and secrets are stored centrally. Users never see the plain-text password — they request access and the system authenticates on their behalf. Think of it as a bank safe for all your most sensitive IT credentials.',
   chips:['AES-256 Encryption','Zero Knowledge','Centralized Storage','Tamper-proof']},

  {id:'leastpriv', group:'core',    x:-320,y:140,  r:46, label:'Least\nPrivilege',
   desc:'The principle that every user and system should have only the minimum access needed to do their job — nothing more. PAM enforces this automatically. If a developer only needs to access one database, they get exactly that — not admin rights to the whole server.',
   chips:['Zero Standing Privilege','JIT Access','Role-Based','Access Expiry']},

  {id:'jit',       group:'core',    x:320, y:140,  r:46, label:'Just-In-Time\nAccess',
   desc:'JIT Access means privileged access is granted only when needed, for a limited time window, then automatically revoked. Instead of an admin having permanent root access, they request it, it\'s approved, they do the task, and access disappears. Massively reduces the attack window.',
   chips:['Time-Limited','Auto-Revoke','Approval Workflow','Request-Release']},

  {id:'session',   group:'core',    x:0,   y:-290, r:46, label:'Session\nMonitoring',
   desc:'Every privileged session is recorded — keystrokes, commands, mouse clicks, screen activity. Administrators can watch live sessions in real time and kill them instantly if suspicious activity is detected. Recordings are stored for forensic analysis and compliance audits.',
   chips:['Screen Recording','Keystroke Logging','Live Shadow','Forensics','Alert on Anomaly']},

  {id:'audit',     group:'core',    x:0,   y:290,  r:46, label:'Audit\nTrails',
   desc:'Every action taken with a privileged account is logged — who accessed what, when, from where, and what they did. These immutable audit trails are critical for compliance, incident response, and forensic investigations. PAM creates accountability where anonymous shared accounts once had none.',
   chips:['Who Did What','Immutable Logs','SIEM Integration','Incident Response']},

  {id:'mfa',       group:'feature', x:-220,y:-290, r:38, label:'MFA',
   desc:'Multi-Factor Authentication adds a second verification step before granting access to the vault or privileged accounts. Even if a password is stolen, an attacker can\'t get in without the second factor. PAM enforces MFA for all privileged access — no exceptions.',
   chips:['TOTP','Push Notifications','Hardware Keys','Biometrics']},

  {id:'autorotate',group:'feature', x:220, y:-290, r:38, label:'Password\nRotation',
   desc:'PAM automatically rotates (changes) privileged passwords on a schedule — daily, weekly, or after each use. This eliminates stale credentials that attackers love to exploit. Even if a password leaks, it\'s only valid for a short time before the system changes it automatically.',
   chips:['Scheduled Rotation','Post-Session Rotation','Service Accounts','Zero Hard-Coded Creds']},

  {id:'discovery', group:'feature', x:-380,y:0,    r:38, label:'Account\nDiscovery',
   desc:'PAM automatically scans your entire network to find all privileged accounts — including ones IT teams didn\'t even know existed (shadow accounts). It discovers accounts on Windows, Linux, Mac, databases, VMs, and network devices and brings them under centralized management.',
   chips:['Network Scan','Shadow Accounts','Auto-Onboarding','Continuous Discovery']},

  {id:'rdp',       group:'feature', x:380, y:0,    r:38, label:'Remote\nAccess (RDP/SSH)',
   desc:'PAM enables one-click secure remote connections (RDP, SSH, SQL) to servers and systems — without ever revealing the password to the user. The system injects credentials automatically. Sessions are recorded. No VPN required for third-party vendors.',
   chips:['No VPN Needed','Zero Credential Exposure','One-Click Launch','Session Recording']},

  {id:'secrets',   group:'feature', x:220, y:290,  r:38, label:'Secrets\nManagement',
   desc:'Modern applications, CI/CD pipelines, and scripts need passwords and API keys to function. PAM\'s secrets manager injects these secrets at runtime through APIs and CLIs — eliminating dangerous hard-coded credentials in source code and configuration files.',
   chips:['CI/CD Pipeline','API Keys','DevOps','No Hard-Coded Creds','Runtime Injection']},

  {id:'epm',       group:'feature', x:-220,y:290,  r:38, label:'Endpoint\nPrivilege Mgmt',
   desc:'EPM removes local admin rights from endpoint devices (laptops, workstations) while still letting users run specific applications with elevated privileges when needed — without making them full admins. This dramatically reduces the blast radius of malware and insider threats.',
   chips:['Remove Local Admin','App-Level Elevation','JIT Admin Access','Ransomware Defense']},

  // ── SECURDEN ──
  {id:'securden',  group:'securden',x:0,   y:0,   r:0, label:'', desc:'', chips:[]}, // placeholder, won't render
  {id:'sco',       group:'securden',x:0,   y:-500,r:62, label:'Securden\nInc.',
   sub:'Identity Security Platform',
   desc:'Securden is a US-based cybersecurity company (Wilmington, DE) founded with one mission: making PAM simple, affordable, and complete. Their tagline is "Escape the maze of disjointed tools" — replacing a pile of separate security products with a single unified platform covering PAM, EPM, IGA, CIEM, and AI Agent security. CEO: Bala Venkatramani. Available on-prem, self-hosted, or SaaS.',
   chips:['Founded in USA','On-Prem / SaaS','30-Day Free Trial','SMB to Enterprise','MSP-Focused']},

  {id:'upam',      group:'product', x:-220,y:-430, r:48, label:'Unified\nPAM',
   desc:'Securden\'s flagship product — a single platform that combines privileged identity management, just-in-time remote access, session management, least privilege enforcement, and endpoint privilege management. Replaces 4–5 separate tools in one package. Deployable in minutes.',
   chips:['All-in-One','Quick Deploy','On-Prem or SaaS','PASAM + PEDM']},

  {id:'pwvault',   group:'product', x:220, y:-430, r:48, label:'Password\nVault',
   desc:'Securden\'s enterprise password manager — stores, shares, and tracks all passwords, SSH keys, certificates, and secrets centrally. Teams can securely share credentials with full control and auditing. Browser extensions enable autofill without exposing plain-text passwords.',
   chips:['Browser Extension','Team Sharing','MFA Enforced','SSH Key Management','Certificates']},

  {id:'vendorpam', group:'product', x:-380,y:-330, r:40, label:'Vendor\nPAM',
   desc:'Provides secure, just-in-time remote access for third-party vendors and contractors — without requiring a VPN, agent software, or opening firewall ports. Vendors connect through a secure browser-based gateway. All sessions are recorded and time-limited.',
   chips:['No VPN','No Agent','Browser-Based','Contractor Access','Session Recording']},

  {id:'upammsp',   group:'product', x:380, y:-330, r:40, label:'Unified PAM\nfor MSPs',
   desc:'A first-of-its-kind PAM platform built for Managed Service Providers. Multi-tenant architecture means MSPs can manage hundreds of clients from one interface, with complete data segregation between clients. Launched March 2024. Enables PAM-as-a-Service offerings.',
   chips:['Multi-Tenant','Data Segregation','PAMaaS','Client Isolation','Launched 2024']},

  {id:'selfservice',group:'product',x:0,   y:-620, r:38, label:'Password\nSelf-Service',
   desc:'Lets end users reset their own domain passwords and unlock their accounts without calling the helpdesk. Reduces IT support burden while maintaining security policies. Users verify identity through MFA before being allowed to reset.',
   chips:['Reduce Helpdesk Load','Self-Service Reset','MFA Verified','Domain Accounts']},

  {id:'ciem',      group:'product', x:-200,y:-620, r:38, label:'CIEM\n(Cloud)',
   desc:'Cloud Infrastructure Entitlement Management — manages identities, access, and permissions across multi-cloud environments (AWS, Azure, GCP). Discovers over-privileged cloud roles, enforces least privilege in the cloud, and prevents cloud misconfigurations.',
   chips:['AWS / Azure / GCP','Cloud Permissions','Over-Privilege Detection','Multi-Cloud']},

  {id:'secretsmgr',group:'product',x:200, y:-620, r:38, label:'Secrets\nManager',
   desc:'A dedicated product for DevOps teams to store, manage, and distribute secrets used in CI/CD pipelines. Injects API keys, tokens, and passwords into automation scripts at runtime — so developers never hard-code credentials in source code.',
   chips:['CI/CD Pipelines','API Injection','DevOps Native','GitHub Actions','Jenkins']},

  // ── THREATS ──
  {id:'insider',   group:'threat',  x:-500,y:200,  r:42, label:'Insider\nThreats',
   desc:'Malicious or negligent employees with privileged access can cause devastating damage. PAM limits what each person can access, records every action, and alerts on anomalies — so insider threats are detected fast and their blast radius is minimized.',
   chips:['Behavior Analytics','Least Privilege','Session Recording','Access Reviews']},

  {id:'ransomware',group:'threat',  x:-500,y:330,  r:42, label:'Ransomware\n& Malware',
   desc:'Ransomware needs admin rights to spread across a network and encrypt files at scale. By removing local admin rights (EPM) and restricting privileged account use, PAM starves ransomware of the access it needs to propagate. EPM is one of the most effective ransomware defenses available.',
   chips:['Remove Admin Rights','Application Control','Lateral Movement Block','EPM']},

  {id:'credential',group:'threat',  x:-500,y:460,  r:42, label:'Credential\nTheft',
   desc:'Attackers steal passwords through phishing, keyloggers, or data breaches. PAM renders stolen credentials useless — passwords are rotated automatically, never shown in plain text, and MFA is enforced. Even if an attacker has the password, they can\'t use it.',
   chips:['Auto Password Rotation','MFA','No Plain-Text Display','Phishing Resistance']},

  {id:'thirdparty',group:'threat',  x:-500,y:590,  r:42, label:'Third-Party\nRisk',
   desc:'Contractors and vendors are a major attack vector — they often have excessive, long-term access. PAM enforces time-limited, task-specific access for all third parties. Sessions are monitored. Access is automatically revoked when the task is done.',
   chips:['JIT Access','Session Monitoring','Auto-Revoke','No VPN Required','Vendor PAM']},

  // ── COMPLIANCE ──
  {id:'nist',      group:'compliance',x:500,y:200,  r:38, label:'NIST',
   desc:'The NIST Cybersecurity Framework and SP 800-53 both require strong privileged access controls, least privilege enforcement, audit logging, and account management. Securden\'s PAM platform directly satisfies these requirements and generates compliance reports automatically.',
   chips:['NIST CSF','SP 800-53','Automated Reports','Audit Logs']},

  {id:'pci',       group:'compliance',x:500,y:310,  r:38, label:'PCI-DSS',
   desc:'Payment Card Industry Data Security Standard requires strict control over who accesses cardholder data environments. PAM ensures all access is authenticated, time-limited, and fully audited — directly addressing PCI-DSS requirements 7, 8, and 10.',
   chips:['Req. 7,8,10','Access Control','Audit Trail','Session Monitoring']},

  {id:'hipaa',     group:'compliance',x:500,y:420,  r:38, label:'HIPAA',
   desc:'Healthcare organizations must protect patient data (PHI). HIPAA requires access controls, audit controls, and transmission security — all enforced by PAM. Securden helps healthcare providers demonstrate compliance during audits with detailed access reports.',
   chips:['PHI Protection','Access Controls','Audit Controls','Healthcare']},

  {id:'gdpr',      group:'compliance',x:500,y:530,  r:38, label:'GDPR /\nNIS2',
   desc:'European data protection regulations (GDPR, NIS2, DORA) require organizations to protect personal data and critical infrastructure. PAM\'s audit trails, access controls, and session monitoring provide the technical controls and documentation needed for compliance.',
   chips:['Data Protection','Access Logs','NIS2','DORA','FINRA','SAMA']},
];

// Remove placeholder
const renderNodes = nodes.filter(n=>n.r>0);

const edges=[
  // Core connections
  ['pam','privileged'],['pam','vault'],['pam','leastpriv'],['pam','jit'],
  ['pam','session'],['pam','audit'],
  ['vault','mfa'],['vault','autorotate'],
  ['pam','discovery'],['pam','rdp'],['pam','secrets'],['pam','epm'],
  // Securden hub
  ['sco','upam'],['sco','pwvault'],['sco','vendorpam'],['sco','upammsp'],
  ['sco','selfservice'],['sco','ciem'],['sco','secretsmgr'],
  // Product ↔ Core
  ['upam','pam'],['upam','session'],['upam','jit'],['upam','epm'],
  ['pwvault','vault'],['pwvault','mfa'],
  ['vendorpam','jit'],['vendorpam','rdp'],
  ['secretsmgr','secrets'],
  ['epm','leastpriv'],['epm','ransomware'],
  // Threats ↔ Core
  ['pam','insider'],['pam','ransomware'],['pam','credential'],['pam','thirdparty'],
  ['leastpriv','insider'],['session','insider'],
  ['epm','ransomware'],
  ['autorotate','credential'],['mfa','credential'],
  ['vendorpam','thirdparty'],['jit','thirdparty'],
  // Compliance ↔ Core
  ['audit','nist'],['audit','pci'],['audit','hipaa'],['audit','gdpr'],
  ['pam','nist'],['pam','pci'],['pam','hipaa'],['pam','gdpr'],
];

// ═══════════════════════════════════════════════════════
//  ENGINE
// ═══════════════════════════════════════════════════════
const canvas=document.getElementById('c');
const ctx=canvas.getContext('2d');
let W,H,dpr;
let ox=0,oy=0,scale=1;
let drag=false,lmx=0,lmy=0;
let hovered=null,selected=null;
let animating=true, tick=0;
let highlightGroup=null;
let searchQuery='';

function resize(){
  dpr=window.devicePixelRatio||1;
  W=window.innerWidth; H=window.innerHeight;
  canvas.width=W*dpr; canvas.height=H*dpr;
  canvas.style.width=W+'px'; canvas.style.height=H+'px';
  ctx.setTransform(dpr,0,0,dpr,0,0);
  ox=W/2; oy=H/2;
}

function toS(x,y){return[x*scale+ox,y*scale+oy];}
function fromS(sx,sy){return[(sx-ox)/scale,(sy-oy)/scale];}

function getColor(n){ return COLOR[n.group]||'#888'; }

function isVisible(n){
  if(!searchQuery) return true;
  return n.label.toLowerCase().includes(searchQuery)||
    (n.sub||'').toLowerCase().includes(searchQuery)||
    (n.desc||'').toLowerCase().includes(searchQuery)||
    (n.chips||[]).some(c=>c.toLowerCase().includes(searchQuery));
}

function drawEdge(a,b){
  const na=renderNodes.find(n=>n.id===a);
  const nb=renderNodes.find(n=>n.id===b);
  if(!na||!nb) return;
  if(searchQuery&&(!isVisible(na)||!isVisible(nb))) return;

  const [ax,ay]=toS(na.x,na.y);
  const [bx,by]=toS(nb.x,nb.y);

  const isSel = selected && (selected.id===a||selected.id===b);
  const isHov = hovered && (hovered.id===a||hovered.id===b);
  const col = isSel ? getColor(selected) : isHov ? getColor(hovered) : null;

  ctx.save();
  ctx.beginPath();
  ctx.moveTo(ax,ay); ctx.lineTo(bx,by);
  if(col){
    ctx.strokeStyle=col+'aa';
    ctx.lineWidth=2;
    ctx.shadowColor=col;
    ctx.shadowBlur=8;
  } else {
    ctx.strokeStyle='rgba(80,90,140,0.18)';
    ctx.lineWidth=1;
    ctx.setLineDash([3,9]);
  }
  ctx.stroke();
  ctx.restore();
}

function drawNode(n){
  if(!isVisible(n)){
    // draw faded
    const [sx,sy]=toS(n.x,n.y);
    const r=n.r*scale;
    ctx.save();
    ctx.globalAlpha=0.12;
    ctx.beginPath();
    ctx.arc(sx,sy,r,0,Math.PI*2);
    ctx.fillStyle=getColor(n)+'33';
    ctx.fill();
    ctx.restore();
    return;
  }

  const [sx,sy]=toS(n.x,n.y);
  const r=n.r*scale;
  const col=getColor(n);
  const isSel=selected&&selected.id===n.id;
  const isHov=hovered&&hovered.id===n.id;

  ctx.save();

  // Glow
  if(isSel||isHov){
    const gr=ctx.createRadialGradient(sx,sy,r*.4,sx,sy,r*2.5);
    gr.addColorStop(0,col+'44');
    gr.addColorStop(1,'transparent');
    ctx.fillStyle=gr;
    ctx.beginPath();
    ctx.arc(sx,sy,r*2.5,0,Math.PI*2);
    ctx.fill();
  }

  // PAM center pulse rings
  if(n.id==='pam'&&animating){
    const p=(Math.sin(tick*.035)+1)*.5;
    [1.35,1.65,2.0].forEach((m,i)=>{
      ctx.beginPath();
      ctx.arc(sx,sy,r*m+p*6,0,Math.PI*2);
      ctx.strokeStyle=col+(i===0?'40':i===1?'28':'16');
      ctx.lineWidth=1.5;
      ctx.stroke();
    });
  }

  // Securden center pulse rings
  if(n.id==='sco'&&animating){
    const p=(Math.sin(tick*.04+1)+1)*.5;
    [1.3,1.7].forEach((m,i)=>{
      ctx.beginPath();
      ctx.arc(sx,sy,r*m+p*5,0,Math.PI*2);
      ctx.strokeStyle=col+(i===0?'44':'22');
      ctx.lineWidth=1.5;
      ctx.stroke();
    });
  }

  // Fill
  const grad=ctx.createRadialGradient(sx-r*.25,sy-r*.25,r*.05,sx,sy,r);
  grad.addColorStop(0,col+(isSel?'ff':'cc'));
  grad.addColorStop(0.6,col+(isSel?'88':'55'));
  grad.addColorStop(1,col+'22');
  ctx.beginPath();
  ctx.arc(sx,sy,r,0,Math.PI*2);
  ctx.fillStyle=grad;
  ctx.fill();

  // Border
  ctx.beginPath();
  ctx.arc(sx,sy,r,0,Math.PI*2);
  ctx.strokeStyle=isSel?'#fff':col+(isHov?'dd':'88');
  ctx.lineWidth=isSel?2.5:1.5;
  ctx.stroke();

  // Label
  const lines=n.label.split('\n');
  const fs=Math.max(9,Math.min(14,r*.34));
  ctx.font=`700 ${fs}px 'Space Grotesk',sans-serif`;
  ctx.fillStyle='#ffffff';
  ctx.textAlign='center';
  ctx.textBaseline='middle';
  ctx.shadowColor='rgba(0,0,0,.9)';
  ctx.shadowBlur=5;
  const lh=fs*1.25;
  const startY=sy-(lines.length-1)*lh/2;
  lines.forEach((line,i)=>ctx.fillText(line,sx,startY+i*lh));

  // Sub label for big nodes
  if(n.sub&&r>40){
    const subFs=Math.max(7,r*.16);
    ctx.font=`400 ${subFs}px 'JetBrains Mono',monospace`;
    ctx.fillStyle=col+'cc';
    ctx.shadowBlur=0;
    ctx.fillText(n.sub.replace('\n',' '),sx,startY+lines.length*lh+subFs*.5);
  }

  ctx.restore();
}

function frame(){
  tick++;
  ctx.clearRect(0,0,W,H);
  edges.forEach(([a,b])=>drawEdge(a,b));
  renderNodes.forEach(n=>drawNode(n));
  requestAnimationFrame(frame);
}

// ═══════════════════════════════════════════════════════
//  INTERACTION
// ═══════════════════════════════════════════════════════
function getNode(mx,my){
  const[wx,wy]=fromS(mx,my);
  return renderNodes.find(n=>{
    if(!isVisible(n)) return false;
    const dx=n.x-wx,dy=n.y-wy;
    return Math.sqrt(dx*dx+dy*dy)<n.r;
  })||null;
}

canvas.addEventListener('mousedown',e=>{drag=true;lmx=e.clientX;lmy=e.clientY;});
canvas.addEventListener('mousemove',e=>{
  if(drag){ox+=e.clientX-lmx;oy+=e.clientY-lmy;lmx=e.clientX;lmy=e.clientY;}
  else{hovered=getNode(e.clientX,e.clientY);canvas.style.cursor=hovered?'pointer':'grab';}
});
canvas.addEventListener('mouseup',e=>{
  const moved=Math.abs(e.clientX-lmx)>4||Math.abs(e.clientY-lmy)>4;
  drag=false;
  if(!moved){
    const n=getNode(e.clientX,e.clientY);
    if(n){selected=n;showPanel(n);}
    else{selected=null;hidePanel();}
  }
});
canvas.addEventListener('wheel',e=>{
  e.preventDefault();
  const f=e.deltaY>0?.9:1.1;
  ox=e.clientX+(ox-e.clientX)*f;
  oy=e.clientY+(oy-e.clientY)*f;
  scale=Math.max(.2,Math.min(3,scale*f));
},{passive:false});

// Touch
let ltd=null;
canvas.addEventListener('touchstart',e=>{if(e.touches.length===1){drag=true;lmx=e.touches[0].clientX;lmy=e.touches[0].clientY;}});
canvas.addEventListener('touchmove',e=>{
  e.preventDefault();
  if(e.touches.length===1&&drag){ox+=e.touches[0].clientX-lmx;oy+=e.touches[0].clientY-lmy;lmx=e.touches[0].clientX;lmy=e.touches[0].clientY;}
  else if(e.touches.length===2){
    const d=Math.hypot(e.touches[0].clientX-e.touches[1].clientX,e.touches[0].clientY-e.touches[1].clientY);
    if(ltd){scale=Math.max(.2,Math.min(3,scale*d/ltd));}
    ltd=d;
  }
},{passive:false});
canvas.addEventListener('touchend',e=>{drag=false;ltd=null;
  if(e.changedTouches.length===1){const t=e.changedTouches[0];const n=getNode(t.clientX,t.clientY);if(n){selected=n;showPanel(n);}else{selected=null;hidePanel();}}
});

// Legend filtering
document.querySelectorAll('.leg-item').forEach(el=>{
  el.addEventListener('click',()=>{
    const g=el.dataset.group;
    // flash all nodes in that group
    renderNodes.filter(n=>n.group===g).forEach(n=>{n._flash=20;});
  });
});

// Search
document.getElementById('search').addEventListener('input',e=>{
  searchQuery=e.target.value.toLowerCase().trim();
});

// ═══════════════════════════════════════════════════════
//  PANEL
// ═══════════════════════════════════════════════════════
function showPanel(n){
  const col=getColor(n);
  document.getElementById('panel-tag').textContent=G[n.group]||n.group;
  document.getElementById('panel-tag').style.color=col;
  document.getElementById('panel-title').textContent=n.label.replace('\n',' ')+(n.sub?' — '+n.sub.replace('\n',' '):'');
  document.getElementById('panel-title').style.color=col;
  document.getElementById('panel-desc').textContent=n.desc;
  const chips=document.getElementById('panel-chips');
  chips.innerHTML='';
  (n.chips||[]).forEach(c=>{
    const d=document.createElement('div');
    d.className='chip';
    d.textContent=c;
    d.style.borderColor=col+'55';
    d.style.color=col;
    d.style.background=col+'0f';
    chips.appendChild(d);
  });
  document.getElementById('panel').classList.add('open');
}
function hidePanel(){document.getElementById('panel').classList.remove('open');}
document.getElementById('panel-close').addEventListener('click',()=>{selected=null;hidePanel();});

// ═══════════════════════════════════════════════════════
//  CONTROLS
// ═══════════════════════════════════════════════════════
document.getElementById('btn-reset').addEventListener('click',()=>{ox=W/2;oy=H/2;scale=1;});
document.getElementById('btn-fit').addEventListener('click',()=>{
  const xs=renderNodes.map(n=>n.x),ys=renderNodes.map(n=>n.y);
  const minX=Math.min(...xs),maxX=Math.max(...xs),minY=Math.min(...ys),maxY=Math.max(...ys);
  const pad=120;
  const sx=(W-pad*2)/(maxX-minX+160),sy=(H-pad*2)/(maxY-minY+160);
  scale=Math.min(sx,sy,.9);
  ox=W/2-((minX+maxX)/2)*scale;
  oy=H/2-((minY+maxY)/2)*scale;
});
document.getElementById('btn-anim').addEventListener('click',()=>{animating=!animating;});

// ═══════════════════════════════════════════════════════
//  INIT
// ═══════════════════════════════════════════════════════
resize();
window.addEventListener('resize',resize);

// Start centered on PAM
setTimeout(()=>{
  ox=W/2; oy=H/2+80; scale=.72;
},50);

frame();
</script>
</body>
</html>
