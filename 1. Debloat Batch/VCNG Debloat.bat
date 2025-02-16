@echo off

set "FolderCount=0"
set "FileCount=0"
set "PackfileCount=0"

set /p ConfirmDebloat="Do you want to debloat this copy of VCNG? Remember that it is recommended to do it on a stock directory. (Y/N): "

if /i "%ConfirmDebloat%"=="Y" (
    for %%A in (
        "Activation"
        "data_launch"
        "ShaderOverDax1"
        "common\shaders"
        "common\data\cdimages\script_sources"
        "common\data\script"
        "common\data\shaders"
        "pc\html"
        "pc\data\face"
        "pc\data\frontend"
    ) do (
        if exist "%%A" (
            rd /s /q "%%A"
            set /a FolderCount+=1
            echo Deleted folder: %%A
        ) else (
	        echo Could not find folder: %%A
        )
    )
    
    for %%B in (
        "876bd1d9393712ac.bin"
        "asilog.txt"
        "d3d9.dll"
        "dax.dll"
        "DFA.dll"
        "dsound.dll"
        "DX9Settings.ini"
        "effect.txt"
        "enbbloom.fx"
        "enbclouds.bmp"
        "enbclouds.fx"
        "enbeffect.fx"
        "enbpalette.bmp"
        "enbseries.ini"
        "enbspritelight.png"
        "files.txt"
        "GameuxInstallHelper.dll"
        "gta4Browser.exe"
        "GTAIV.exe.cat"
        "GTAIV.exe.cdf"
        "GTAIV.exe.cfg"
        "GTAIVGDF.dll"
        "lang.ini"
        "LaunchGTAIV.exe"
        "LiveTokenHelper.dll"
        "logo-paul.bmp"
        "paul.dll"
        "rld.bin"
        "rld.dll"
        "vcNElaunch.exe"
        "xlive_d.dll"
        "common\data\cdimages\navgen_script.img"
        "common\data\fragments\*.tune"
        "common\data\paths\carrec*.rrr"
        "common\data\action_table.xls"
        "common\data\action_table_backup.csv"
        "common\data\animviewer.dat"
        "common\data\animviewer_images.txt"
        "common\data\ar_stats.dat"
        "common\data\carmods.dat"
        "common\data\cj_gta.dat"
        "common\data\cj_images.txt"
        "common\data\clothes.dat"
        "common\data\credits_360.dat"
        "common\data\credits_PS3.dat"
        "common\data\gtaRainEmitter.xml"
        "common\data\gtaRainRender.xml"
        "common\data\gtaStormEmitter.xml"
        "common\data\gtaStormRender.xml"
        "common\data\frontend.dat"
        "common\data\frontend_360.dat"
        "common\data\frontend_ps3.dat"
        "common\data\furnitur.dat"
        "common\data\loadingscreens_360.dat"
        "common\data\loadingscreens_ps3.dat"
        "common\data\loadingscreens_ingame_360.dat"
        "common\data\loadingscreens_ingame_ps3.dat"
        "common\data\main.sc"
        "common\data\melee.dat"
        "common\data\numplate.dat"
        "common\data\object.dat"
        "common\data\old_anim_action_table.xls"
        "common\data\ped.dat"
        "common\data\pedProps.dat"
        "common\data\plants.dat"
        "common\data\polydensity.dat"
        "common\data\popcycle.datnew"
        "common\data\precincts.dat"
        "common\data\songlist.csv"
        "common\data\statdisp.dat"
        "common\data\stockshake.txt"
        "common\data\txdcut.ide"
        "common\data\version.txt"
        "common\data\visualSettings.xls"
        "common\data\worldblanket.dat"
        "pc\audio\Config\waveslot_.xml"
        "pc\data\cdimages\navmeshes_animviewer.img"
        "pc\data\cdimages\scripttxds.img"
        "pc\data\Benchmark.cli"
        "pc\data\Benchmark.tag"
        "pc\data\filelist.pak"
        "pc\data\gta4pc.png"
        "pc\data\loading.rpf"
        "pc\data\radiohud.dat"
        "pc\data\timecyclemodifiers*.dat"
        "pc\data\effects\gta_entity.wpfl"
        "pc\data\effects\gta_script.wpfl"
        "pc\models\plantsmgr.wdd"
        "pc\models\radar.wdd"
        "pc\textures\axistut.wtd"
        "pc\textures\bowling.wtd"
        "pc\textures\browser.wtd"
        "pc\textures\buttons_ps3.wtd"
        "pc\textures\cashmachine.wtd"
        "pc\textures\computer.wtd"
        "pc\textures\cs_location.wtd"
        "pc\textures\darts.wtd"
        "pc\textures\dm_location.wtd"
        "pc\textures\eyeadvert_0.wtd"
        "pc\textures\frontend_ps3.wtd"
        "pc\textures\leaderboards.wtd"
        "pc\textures\level_design.wtd"
        "pc\textures\loadingscreens_360.wtd"
        "pc\textures\loadingscreens_ps3.wtd"
        "pc\textures\loadingscreens_v2.wtd"
        "pc\textures\network.wtd"
        "pc\textures\pdb*.wtd"
        "pc\textures\plantsmgr.wtd"
        "pc\textures\policecomputer.wtd"
        "pc\textures\policedb.wtd"
        "pc\textures\policedb2000.wtd"
        "pc\textures\proc_mail.wtd"
        "pc\textures\qub3d.wtd"
        "pc\textures\race_*.wtd"
        "pc\textures\radio_hud.wtd"
        "pc\textures\space_hud.wtd"
        "pc\textures\tb_location.wtd"
        "pc\textures\vehicle.wtd"
        "pc\textures\visualeffects.wtd"
        "pc\textures\water.wtd"
        "pc\textures\web*.wtd"
        "pc\textures\zombie.wtd"
        "pc\textures\test.txt"
        "pc\textures\title_no_site_e1.wtd"
        "pc\textures\title_no_site_e2.wtd"
        "pc\textures\title_offline_e1*.wtd"
        "pc\textures\title_offline_e2*.wtd"
        "pc\ab_lock.txt"
    ) do (
        if exist "%%B" (
            del /q "%%B"
            set /a FileCount+=1
            echo Deleted file: %%B
        ) else (
            echo Could not find file: %%B
        )
    )
) else (
    echo Nope, got it.
)

set /p ConfirmPackfiles="Do you want to delete Russian dub audio packfiles? Saves about 1.5gb of space. (Y/N): "

if /i "%ConfirmPackfiles%"=="Y" (
    for %%C in (
        "pc\audio\Sfx\radio_emotion_ru.rpf"
        "pc\audio\Sfx\radio_wildstyle_ru.rpf"
        "pc\audio\Sfx\radio_wave103_ru.rpf"
        "pc\audio\Sfx\radio_vrock_ru.rpf"
        "pc\audio\Sfx\radio_vcpr_ru.rpf"
        "pc\audio\Sfx\radio_kchat_ru.rpf"
        "pc\audio\Sfx\radio_flash_ru.rpf"
        "pc\audio\Sfx\radio_fever_ru.rpf"
        "pc\audio\Sfx\radio_espant_ru.rpf"
        "pc\audio\Sfx\cutscenes_ru.rpf"
        "pc\audio\Sfx\scripted_speech_ru.rpf"
    ) do (
        if exist %%C (
            del /q %%C
            set /a PackfileCount+=1
            echo Deleted packfile: %%C
        ) else (
            echo Packfile not found: %%C
        )
    )
) else (
    echo Nope, got it.
)

echo Debloat complete.

echo Total folders deleted: %FolderCount%
echo Total files deleted: %FileCount%
echo Total packfiles deleted: %PackfileCount%

pause

del "%~f0"