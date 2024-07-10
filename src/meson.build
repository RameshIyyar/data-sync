# SPDX-License-Identifier: Apache-2.0

phosphor_logging = dependency('phosphor-logging')
sdbusplus = dependency('sdbusplus')
sdeventplus = dependency('sdeventplus')

rbmc_data_sync_sources = [
    'phosphor-rbmc-data-sync-mgr_main.cpp'
  ]

rbmc_data_sync_dependencies = [
    phosphor_logging,
    sdeventplus,
  ]

inc_dir = include_directories('.')
executable('phosphor-rbmc-data-sync-mgr',
    rbmc_data_sync_sources,
    dependencies: rbmc_data_sync_dependencies,
    include_directories: inc_dir,
    install : true
  )
