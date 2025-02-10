git checkout main
git rebase --abort 2>$null
git merge --abort 2>$null
git reset --merge 2>$null
git fsck --full
git fetch origin
git diff --stat origin/main
git pull origin main --rebase --strategy-option=theirs
git config --global merge.conflictstyle diff3
git add .
git commit -m "Resolviendo conflictos y actualizando el repositorio"
git push origin main
git status
git log origin/main --oneline
git remote -v
git clean -fd
git count-objects -vH
Write-Host "Repositorio actualizado exitosamente"