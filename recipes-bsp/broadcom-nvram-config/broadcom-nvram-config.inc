LICENSE = "Proprietary"
LIC_FILES_CHKSUM = "file://LICENCE.broadcom_bcm43xx;md5=3160c14df7228891b868060e1951dfbc"

SRC_URI = " \
   file://LICENCE.broadcom_bcm43xx \
"

S = "${UNPACKDIR}"
BRCM_FWDIR = "${nonarch_base_libdir}/firmware/brcm"
CHIP_MODEL ?= "Invalid"

do_install() {
    install -d  ${D}${BRCM_FWDIR}

    cp -r ${UNPACKDIR}/brcmfmac${CHIP_MODEL}-sdio.txt \
        ${D}${BRCM_FWDIR}
}

SRC_URI += " \
   file://brcmfmac${CHIP_MODEL}-sdio.txt \
"

FILES:${PN} = " \
  ${BRCM_FWDIR}/brcmfmac${CHIP_MODEL}-sdio.txt \
"

RDEPENDS:${PN} = " \ 
  linux-firmware-bcm${CHIP_MODEL} \
"

PACKAGE_ARCH = "${MACHINE_ARCH}"
