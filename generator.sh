find . | grep  -E "\.(cpp|java|py)$" | cut -c3-100 > content.txt
rm templateNotebook.log
rm templateNotebook.out
rm templateNotebook.toc
rm templateNotebook.aux
rm templateNotebook.fdb_latexmk
rm templateNotebook.fls
