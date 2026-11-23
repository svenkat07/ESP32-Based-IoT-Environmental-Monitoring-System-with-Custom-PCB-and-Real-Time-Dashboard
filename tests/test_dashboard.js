// Static smoke tests for the offline demo. Run from any working directory.
const fs = require('node:fs');
const path = require('node:path');
const assert = require('node:assert/strict');
const html = fs.readFileSync(path.join(__dirname, '..', 'dashboard', 'index.html'), 'utf8');
for (const term of ['SIMULATED DATA', 'NOT LIVE HARDWARE', 'generateSample()', 'Export CSV', 'temperature', 'humidity', 'pressure', 'Reset', 'Pause']) {
  assert.ok(html.includes(term), `Missing ${term}`);
}
assert.ok(!html.includes('fetch('), 'Offline simulation should not depend on fetch');
assert.match(html, /setInterval\(update,2000\)/, 'Expected two-second sample interval');
assert.match(html, /history\.length>60/, 'Expected bounded history');
console.log('PASS: offline dashboard smoke checks');
