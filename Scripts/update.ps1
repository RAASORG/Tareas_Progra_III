# Asegurarse de estar en la rama correcta (main)
git checkout main

# Detener cualquier operación de rebase o merge en curso si existe
git rebase --abort 2>$null
git merge --abort 2>$null
git reset --merge 2>$null

# Verificar si hay algún conflicto pendiente
git fsck --full

# Actualizar la rama local con los últimos cambios del repositorio remoto
git fetch origin

# Verificar si hay algún cambio remoto que no se haya traído
git diff --stat origin/main

# Combinar los cambios remotos en la rama local (Forzamos la resolución de conflictos a favor de los cambios locales)
git pull origin main --rebase --strategy-option=theirs

# Si hubo conflictos, los resolvemos con preferencia por los cambios locales
git config --global merge.conflictstyle diff3

# Si los conflictos están resueltos (modificando manualmente o automáticamente),
# agregar los archivos resueltos y confirmar el commit
git add .

# Confirmar el commit de los cambios resueltos
git commit -m "Resolviendo conflictos y actualizando el repositorio"

# Empujar los cambios locales a tu repositorio remoto
git push origin main

# Verificar si hay algo pendiente y mostrar el estado
git status

# Mostrar los logs de los commits remotos para asegurar que todo esté actualizado
git log origin/main --oneline

# Verificar si el repositorio remoto está actualizado correctamente
git remote -v

# Limpiar los archivos no rastreados (si los hay) para mantener el repositorio limpio
git clean -fd

# Ver el espacio en disco ocupado por el repositorio
git count-objects -vH

Write-Host "Repositorio actualizado exitosamente"
