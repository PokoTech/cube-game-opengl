[33mcommit ce3cb37a33c5d8d179c89cbcf223254994f355f2[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Mon Jan 4 11:21:01 2016 +0000

    Changed to intitializer list as per cppcheck linting messages.

[33mcommit 640e10e0e2028705729a2a49820a92c259aef4b1[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Mon Jan 4 10:54:48 2016 +0000

    Changed readme to reflect that we now only support >= F22

[33mcommit 3dbf91e6406d3fe9018db956f081814f49aa361d[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Mon Jan 4 10:51:54 2016 +0000

    Added CI build description.

[33mcommit 8f4bd2e58c95916b782ecbe51ea26768cb8078ec[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Mon Oct 5 09:41:42 2015 +0100

    Update bundled version of boost.m4

[33mcommit 112335204306025257af99c082c0550251fffe88[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Mon Oct 27 10:08:59 2014 +0000

    Added licence

[33mcommit 999746c640e9bed4a1f62f0b3e9f8f9cff7e8b7f[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Mon Oct 27 08:36:30 2014 +0000

    Improved documentation on GameAssetManager and others.

[33mcommit ba6de4b2effa90f46ceac87c766781fc8ab030c2[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Sun Oct 26 20:36:36 2014 +0000

    Fixed spelling mistake.

[33mcommit babe72f246e8865517963609621ab8c5fb6b43fd[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Mon Sep 22 08:59:18 2014 +0100

    Updated readme with DEBUG build instructions.

[33mcommit bb227310eba73838f762d5a3ef4645cf8edb081e[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Thu Sep 18 14:34:57 2014 +0100

    Added missing header file

[33mcommit 47db162b2e68198e1b410219d42c3537a5135340[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Thu Sep 18 14:14:42 2014 +0100

    Added readme

[33mcommit 5e7554954a354af6e0e471824849cdd87228ca51[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Thu Sep 18 13:37:12 2014 +0100

    Corrected projection matrix in shaders.

[33mcommit 72f84d0b974d2135fec7d780bf318d125192601c[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Thu Sep 18 13:32:04 2014 +0100

    Removed camera (no need to introduce this complexity at this stage)

[33mcommit 7c116b59e3e854c64e797d279f77045d3225e6b9[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Thu Sep 18 13:31:48 2014 +0100

    Enable OpenGL depth testing

[33mcommit 197d7684e2bf74019e37818b89a86140d4bbe6b3[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Thu Sep 18 12:56:28 2014 +0100

    Added camera to shaders and better validation to Cube draw method.

[33mcommit 78f60fab9ba9f8e39a759b2af3c5170255fefa07[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Thu Sep 18 10:52:57 2014 +0100

    checkGLError only has an implementation if -DDEBUG is provided.
    Passing all of the vertex & element buffer to the GPU now.

[33mcommit 5ffd3fdbfe2ecba02cf94157e82529d411fffc7d[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Thu Sep 18 10:34:11 2014 +0100

    Changed background colour and window title.

[33mcommit 4f863175a41f4f641233d0521dcac30dacc446cc[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Wed Sep 17 15:55:55 2014 +0100

    Added rotate and scale shaders as copies of the translate one.

[33mcommit fec829cbf8f2a6f71f37b0d20a65e734e4f9d737[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Wed Sep 17 15:46:27 2014 +0100

    Add command line parsing.

[33mcommit 63c92c77c6861f7bfc931c3a504b346b0f47d6ce[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Wed Sep 17 13:44:39 2014 +0100

    Clean up the array initialisation in CubeAsset.

[33mcommit 7cc6748351b5d9fa46d7609c54fbd98f073f42d7[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Wed Sep 17 13:44:26 2014 +0100

    Change window title

[33mcommit 455ed5e36cc98d7a3badb5b6bbc6fdc9086d2050[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Wed Sep 17 13:43:49 2014 +0100

    Don't take a colour from the user, hardcode it.

[33mcommit a28faa4f1d2edf74e362bd56ca220dd16d48829c[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Wed Sep 17 13:37:06 2014 +0100

    Don't pass a GLuint * to the CPU and tell the thing to draw GL_UNSIGNED_SHORT!

[33mcommit ddea9f4e46ff2e17d4c179d3373cf1c9b0f62825[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Wed Sep 17 12:46:59 2014 +0100

    Disable backface culling for debug purposes.

[33mcommit 702252414662d8e63f33715261399c8cc8a4767a[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Wed Sep 17 12:46:42 2014 +0100

    Include cerr and endl in CubeAsset

[33mcommit e1c66633fdb69b41bd4a755034acac09338d57b0[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Wed Sep 17 12:46:06 2014 +0100

    Make GL error reporting more verbose.

[33mcommit 077f812911db7e552ef3abc45b039097deac9439[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Wed Sep 17 12:45:33 2014 +0100

    Put the near and far clipping planes "in front" of the user.

[33mcommit 13a828a3506bdac756ca7422bc2ec9da5f62d488[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Wed Sep 17 11:47:18 2014 +0100

    Create a GameWorld that contains a GameAssetManager

[33mcommit 353c9bcae2e7fc5b119c0a5619f92f63c4494034[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Wed Sep 17 11:46:55 2014 +0100

    Downgrade to GLSL 1.3 due to Intel hardware support.

[33mcommit 9a4aec42c33c4cd04b7e69c1bc7cb77f5d1802f7[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Wed Sep 17 11:46:12 2014 +0100

    Improved the feedback when a shader fails to compile.
    Actually compile shaders in constructor.

[33mcommit d05c9f5806520e062b3417532fd56069b50074c3[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Wed Sep 17 11:15:11 2014 +0100

    Some occurances of window should have been _window.

[33mcommit 771bdff708a5d53092293cf056532ac671a9d7b4[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Wed Sep 17 11:01:11 2014 +0100

    GameAssetManager is no-longer a singleton
    Added GameAssetManager to GameWorld

[33mcommit 174f1e6387c1517366e3e782dd227ed2a16cc7d4[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Wed Sep 17 10:09:50 2014 +0100

    Initialise some Cube buffers on GPU

[33mcommit cae65f74c3c65320e60dacf77540962aec2bc655[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Tue Sep 16 11:19:03 2014 +0100

    Added a partial cube as an asset.

[33mcommit dbc9c9421fc1a2a1e4226940382810b88d20548d[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Tue Sep 16 10:43:07 2014 +0100

    Don't return -1 as a uint, just bail.

[33mcommit 7e6ecdf261295486c4a72d7e84113a70bbf4ec09[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Tue Sep 16 10:39:46 2014 +0100

    Added shader loading code to GameAssetManager
      * Moved GL defines to the make system

[33mcommit 6f2c84586f6972e9955ae366cb43fb68849821dd[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Mon Sep 15 14:25:35 2014 +0100

    Stubbed out some of the management structure.

[33mcommit 7bac8c9911fff7382b8337e1bbd26f5a58eed6f1[m
Author: Aidan Delaney <aidan@ontologyengineering.org>
Date:   Mon Sep 15 12:36:09 2014 +0100

    initial boilerplate
