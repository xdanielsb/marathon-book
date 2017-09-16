find . | grep  -E "\.(cpp|java|py)$" | cut -c3-100 > content.txt

python generator.py &&  rm content.txt && mv templateNotebook.pdf book.pdf && mv book.pdf notebook/ && gnome-open notebook/book.pdf

rm templateNotebook.log
rm templateNotebook.out
rm templateNotebook.toc
rm templateNotebook.aux
rm templateNotebook.fdb_latexmk
rm templateNotebook.fls
