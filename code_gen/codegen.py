import sys, os;

def edit(full_name):
    cmd = 'npp ' + full_name
    import subprocess
    PIPE = subprocess.PIPE
    p = subprocess.Popen(cmd)

cwd = os.path.dirname(os.path.abspath(__file__))

c_template = cwd + r'\c_template.cpp'
desc_file = sys.argv[1]
desc_makro = sys.argv[2]
full_name = sys.argv[3]

if not full_name.endswith('.cpp'):
    full_name += '.cpp'

modules = ['std'] + sys.argv[4:]

if os.path.isfile(full_name) and not '-f' in modules:
    edit(full_name)
    exit()

while '-f' in modules:
    modules.remove('-f')

text = open(c_template, 'r', encoding='ANSI').read();

if os.path.isfile(desc_file):
    desc = open(desc_file, 'r', encoding='ANSI').read()
else:
    desc = desc_file


blocks = {
  'desc': [desc],
  'macro': [desc_makro],
  'import': [],
  'types': [],
  'defines': [],
  'funcs': [],
  'consts': [],
  'main_body': []
}

std_mdls = {
    'io': cwd + r'\io.h',
    'fast': cwd + r'\fast_io.h',
    'pr': cwd + r'\pair.h',
    'ans': cwd + r'\doans.h',
    'std': cwd + r'\std.h',
    'mul': cwd + r'\mul.h',
}

for i in range(0, len(modules)):
    modules[i] = std_mdls.get(modules[i], modules[i]);

for mdl in modules:
    bname = ''
    if not os.path.isfile(mdl):
        print(f"Модуль {mdl} не найден.")
        continue;
    for line in open(mdl, 'r'):
        if line == '\n':
            continue
        if line.startswith('block: '):
            bname = line[7:-1]
            m = ''
        elif line.startswith('@#'):
            if m and bname and not (m in blocks[bname]):
                blocks[bname].append(m)
            m = ''
        else:
            m += line

for blk in blocks:
    for line in blocks[blk]:
        text = text.replace(f'//{blk}//', f'{line}//{blk}//')
    text = text.replace(f'//{blk}//\n', '\n' if blocks[blk] else '')
    text = text.replace(f'//{blk}//', '')

with open(full_name, 'w', encoding='ANSI') as f:
    f.write(text)

edit(full_name)
